// 2023-01-05
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

int n, q;
const int sz = (int)1e5 + 1;
vector<vi> g(sz), tempg(sz);
vi sub(sz), depth(sz), par(sz), top(sz), in(sz);

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

struct st{
    ll v, lazy;
};

vector<st> seg(sz * 4);

void propogate(int node, int l, int r){
	if (seg[node].lazy != 0) {
		seg[node].v += seg[node].lazy * (ll)(r - l + 1);
		if (l != r) {
			seg[node * 2].lazy += seg[node].lazy;
			seg[node * 2 + 1].lazy += seg[node].lazy;
		}
		seg[node].lazy = 0;
	}
}

void segUpdate(int node, int l, int r, int s, int e, ll diff) {
	propogate(node, l, r);
	if (e < l || r < s) return;
	if (s <= l && r <= e) {
		seg[node].lazy += diff;
		propogate(node, l, r);
		return;
	}
	int m{ (l + r) / 2 };
	segUpdate(node * 2, l, m, s, e, diff);
	segUpdate(node * 2 + 1, m + 1, r, s, e, diff);
	seg[node].v = seg[node * 2].v + seg[node * 2 + 1].v;
}

ll segQuery(int node, int l, int r, int s, int e) {
	propogate(node, l, r);
	if (e < l || r < s) return 0;
	if (s <= l && r <= e) return seg[node].v;
	int m{ (l + r) / 2 };
	return segQuery(node * 2, l, m, s, e) + segQuery(node * 2 + 1, m + 1, r, s, e);
}

void update(int a, int b){
    while(top[a] ^ top[b]){
        if(depth[top[a]] < depth[top[b]]) swap(a, b);
        int st = top[a];
        segUpdate(1, 1, n, in[st], in[a], 1);
        a = par[st];
    }
    if(depth[a] > depth[b]) swap(a, b);
    segUpdate(1, 1, n, in[a] + 1, in[b], 1);
}

ll query(int a, int b){
    ll ret = 0;
    while(top[a] ^ top[b]){
        if(depth[top[a]] < depth[top[b]]) swap(a, b);
        int st = top[a];
        ret += segQuery(1, 1, n, in[st], in[a]);
        a = par[st];
    }
    if(depth[a] > depth[b]) swap(a, b);
    ret += segQuery(1, 1, n, in[a] + 1, in[b]);
    return ret;
}

int main(){
	fastio;
    cin >> n >> q;
    for(int i{0}; i < n - 1; ++i){
        int a, b;
        cin >> a >> b;
        tempg[a].push_back(b);
        tempg[b].push_back(a);
    }
    dfs0(); dfs1(); dfs2();
    while(q--){
        char op;
        int a, b;
        cin >> op >> a >> b;
        if(op == 'P'){
            update(a, b);
        }
        else{
            cout << query(a, b) << "\n";
        }   
    }
}
