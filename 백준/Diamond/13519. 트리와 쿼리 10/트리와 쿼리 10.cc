// 2023-01-24
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define vs vector<string>
#define pi pair<int, int>
#define pl pair<ll, ll>
#define vp vector<pi>
#define vpl vector<pl>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int sz = (int)1e5 + 10;
int n;

struct st{
    ll l, r, mid, all, lazy;
    st() : l(-MAX), r(-MAX), mid(-MAX), all(0), lazy(MAX) {}
    st(int _l, int _r, int _mid, int _all, int _lazy) : l(_l), r(_r), mid(_mid), all(_all), lazy(_lazy) {}
};

vector<st> seg(sz * 4);

void merge(st& ret, st left, st right){
    ret.l = max(left.l, left.all + right.l);
    ret.r = max(right.r, left.r + right.all);
    ret.mid = max({left.mid, right.mid, left.r + right.l});
    ret.all = left.all + right.all;
}

void propogate(int node, int l, int r){
	if (seg[node].lazy != MAX) {
        int k = (r - l + 1) * seg[node].lazy;
        if(seg[node].lazy >= 0) seg[node] = st(k, k, k, k, seg[node].lazy);
		else seg[node] = st(seg[node].lazy, seg[node].lazy, seg[node].lazy, k, seg[node].lazy);
		if (l != r) {
			seg[node * 2].lazy = seg[node].lazy;
			seg[node * 2 + 1].lazy = seg[node].lazy;
		}
        seg[node].lazy = MAX;
	}
}

void segUpdate(int node, int l, int r, int s, int e, ll value){
    propogate(node, l, r);
    if(l > e || r < s) return;
    if(s <= l && r <= e) {
        seg[node].lazy = value;
        propogate(node, l, r);
        return;
    }
    int m = (l + r) / 2;
    segUpdate(node * 2, l, m, s, e, value);
    segUpdate(node * 2 + 1, m + 1, r, s, e, value);
    merge(seg[node], seg[node * 2], seg[node * 2 + 1]);
}

st segQuery(int node, int l, int r, int s, int e){
    propogate(node, l, r);
    if(e < l || r < s) return {-MAX, -MAX, -MAX, 0, MAX};
    if(s <= l && r <= e) return seg[node];
    int m = (l + r) / 2;
    st left = segQuery(node * 2, l, m, s, e);
    st right = segQuery(node * 2 + 1, m + 1, r, s, e);
    st ret;
    merge(ret, left, right);
    return ret;
}

vi sub(sz), depth(sz), par(sz), top(sz), in(sz);

vector<vi> tempg(sz);
vector<vi> g(sz);

void dfs0(int cur = 1, int pre = -1){
    for(auto& i : tempg[cur]){
        if(i == pre) continue;
        g[cur].push_back(i);
        dfs0(i, cur);
    }
}

void dfs1(int cur = 1){
    sub[cur] = 1;
    for(auto& i : g[cur]){
        depth[i] = depth[cur] + 1;
        par[i] = cur;
        dfs1(i);
        sub[cur] += sub[i];
        if(sub[i] > sub[g[cur][0]]) swap(i, g[cur][0]);
    }
}

int pv{0};

void dfs2(int cur = 1){
    in[cur] = ++pv;
    for(auto& i : g[cur]){
        if(i == g[cur][0]){
            top[i] = top[cur];
        }
        else top[i] = i;
        dfs2(i);
    }
}

void update(int a, int b, int value){
    while(top[a] ^ top[b]){
        if(depth[top[a]] < depth[top[b]]) swap(a, b);
        int st = top[a];
        segUpdate(1, 1, n, in[st], in[a], value);
        a = par[st];
    }
    if(depth[a] > depth[b]) swap(a, b);
    segUpdate(1, 1, n, in[a], in[b], value);
}

int query(int a, int b){
    if(in[a] > in[b]) swap(a, b);
    st left, right;
    while(top[a] ^ top[b]){
        if(depth[top[a]] > depth[top[b]]){
            int st = top[a];
            merge(left, segQuery(1, 1, n, in[st], in[a]), left);
            a = par[st];
        }
        else{
            int st = top[b];
            merge(right, segQuery(1, 1, n, in[st], in[b]), right);
            b = par[st];
        }
    }
    if(depth[a] > depth[b]) merge(left, segQuery(1, 1 , n, in[b], in[a]), left);
    else merge(right, segQuery(1, 1, n, in[a], in[b]), right);
    swap(left.l, left.r);
    st ret;
    merge(ret, left, right);
    return ret.mid;
}


int main(){
	fastio;
    cin >> n;
    vi weight(n + 1);
    for(int i{1}; i <= n; ++i){
        cin >> weight[i];
    }
    for(int i{0}; i < n - 1; ++i){
        int a, b;
        cin >> a >> b;
        tempg[a].push_back(b);
        tempg[b].push_back(a);
    }
    top[1] = 1;
    dfs0(); dfs1(); dfs2();
    for(int i{1}; i <= n; ++i){
        segUpdate(1, 1, n, in[i], in[i], weight[i]);
    }
    int q;
    cin >> q;
    while(q--){
        int op, a, b, c;
        cin >> op;
        if(op == 1){
            cin >> a >> b;
            cout << max(0, query(a, b)) << "\n";
        }
        else{
            cin >> a >> b >> c;
            update(a, b, c);
        }
    }
}
