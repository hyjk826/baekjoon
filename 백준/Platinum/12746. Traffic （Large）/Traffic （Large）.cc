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

int sz = (int)3e5 + 10;
int n, q;


struct st {
	int v, lazy;
    st() : v(0), lazy(0){}
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

void segUpdate(int node, int l, int r, int s, int e) {
	propogate(node, l, r);
	if (e < l || r < s) return;
	if (s <= l && r <= e) {
		seg[node].lazy += 1;
		propogate(node, l, r);
		return;
	}
	int m{ (l + r) >> 1 };
	segUpdate(node * 2, l, m, s, e);
	segUpdate(node * 2 + 1, m + 1, r, s, e);
	seg[node].v = seg[node << 1].v + seg[node << 1 | 1].v;
}

int segQuery(int node, int l, int r, int s, int e) {
	propogate(node, l, r);
	if (e < l || r < s) return 0;
	if (s <= l && r <= e) return seg[node].v;
	int m{ (l + r) >> 1};
	return segQuery(node * 2, l, m, s, e) + segQuery(node * 2 + 1, m + 1, r, s, e);
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

void update(int a, int b){
    while(top[a] ^ top[b]){
        if(depth[top[a]] < depth[top[b]]) swap(a, b);
        int st = top[a];
        segUpdate(1, 1, n, in[st], in[a]);
        a = par[st];
    }
    if(depth[a] > depth[b]) swap(a, b);
    segUpdate(1, 1, n, in[a] + 1, in[b]);
}


int main(){
	fastio;
    cin >> n >> q;
    for(int i{1}; i <= n - 1; ++i){
        int a, b;
        cin >> a >> b;
        tempg[a].push_back(b);
        tempg[b].push_back(a);
    }
    top[1] = 1;
    dfs0(1, -1);
    dfs1(1);
    dfs2(1);
    while(q--){
        int a, b;
        cin >> a >> b;
        update(a, b);
    }
    int mx{0};
    pi ans;
    for(int i{1}; i <= n; ++i){
        int k = segQuery(1, 1, n, in[i], in[i]);
        if(k > mx){
            mx = k;
            ans = {min(i, par[i]), max(i, par[i])};
        }
        else if(k == mx){
            ans = min(ans, {min(i, par[i]), max(i, par[i])});
        }
    }
    cout << ans.first << " " << ans.second << " " << mx;
}
