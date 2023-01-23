// 2022-12-24
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

vi seg(sz * 4);

void segUpdate(int node, int l, int r, int idx, int value){
    if(l > idx || r < idx) return;
    if(l == r){
        seg[node] = value;
    }
    else{
        int m = (l + r) >> 1;
        segUpdate(node * 2, l, m, idx, value);
        segUpdate(node * 2 + 1, m + 1, r, idx, value);
        seg[node] = seg[node * 2] ^ seg[node * 2 + 1];
    }
}

int segQuery(int node, int l, int r, int s, int e){
    if (r < s || e < l) return 0;
    if (s <= l && r <= e) return seg[node];
    int m = (l + r) >> 1;
    return segQuery(node * 2, l, m, s, e) ^ segQuery(node * 2 + 1, m + 1, r, s, e);
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

int query(int a, int b){
    int ret = 0;
    while(top[a] ^ top[b]){
        if(depth[top[a]] < depth[top[b]]) swap(a, b);
        int st = top[a];
        ret ^= segQuery(1, 1, n, in[st], in[a]);
        a = par[st];
    }
    if(depth[a] > depth[b]) swap(a, b);
    ret ^= segQuery(1, 1, n, in[a], in[b]);
    return ret;
}


int main(){
	fastio;
    int q;
    cin >> n >> q;
    vi vec(n);
    for(int i{1}; i <= n; ++i){
        cin >> vec[i];
    }
    for(int i{0}; i < n - 1; ++i){
        int a, b;
        cin >> a >> b;
        tempg[a].push_back(b);
        tempg[b].push_back(a);
    }
    top[1] = 1;
    dfs0(1, -1);
    dfs1(1);
    dfs2(1);
    for(int i{1}; i <= n; ++i){
        segUpdate(1, 1, n, in[i], vec[i]);
    }
    while(q--){
        int op, a, b;
        cin >> op >> a >> b;
        if(op == 1){
            segUpdate(1, 1, n, in[a], b);
        }
        else{
            cout << query(a, b) << "\n";
        }
    }
}
