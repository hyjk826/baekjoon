// 2022-12-26
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

struct st {
	ll v, lazy;
};

vector<st> segTree(400001);
vector<int> vec(100001);

void update(int node, int l, int r, int s, int e, ll diff) {
	if (segTree[node].lazy != -1) {
		segTree[node].v = segTree[node].lazy * (ll)(r - l + 1);
		if (l != r) {
			segTree[node * 2].lazy = segTree[node].lazy;
			segTree[node * 2 + 1].lazy = segTree[node].lazy;
		}
		segTree[node].lazy = -1;
	}
	if (e < l || r < s) return;
	if (s <= l && r <= e) {
		segTree[node].v = diff * (ll)(r-l+1);
		if (l != r) {
			segTree[node * 2].lazy = diff;
			segTree[node * 2 + 1].lazy = diff;
		}
		return;
	}
	int m{ (l + r) / 2 };
	update(node * 2, l, m, s, e, diff);
	update(node * 2 + 1, m + 1, r, s, e, diff);
	segTree[node].v = segTree[node * 2].v + segTree[node * 2 + 1].v;
}

ll query(int node, int l, int r, int s, int e) {
	if (segTree[node].lazy != -1) {
		segTree[node].v = segTree[node].lazy * (ll)(r - l + 1);
		if (l != r) {
			segTree[node * 2].lazy = segTree[node].lazy;
			segTree[node * 2 + 1].lazy = segTree[node].lazy;
		}
		segTree[node].lazy = -1;
	}
	if (e < l || r < s) return 0;
	if (s <= l && r <= e) return segTree[node].v;
	int m{ (l + r) / 2 };
	return query(node * 2, l, m, s, e) + query(node * 2 + 1, m + 1, r, s, e);
}


int main(){
	fastio;
    int n;
    cin >> n;
    vector<vi> g(n + 1);
    for(int i{1}; i <= n; ++i){
        int a;
        cin >> a;
        if(i == 1) continue;
        g[a].push_back(i);
    }
    vi in(n + 1), out(n + 1);
    int cnt{-1};
    function<void(int, int)> dfs = [&](int cur, int pre){
        in[cur] = ++cnt;
        for(auto& i : g[cur]){
            if(i == pre) continue;
            dfs(i, cur);
        }
        out[cur] = cnt;
    };
    dfs(1, -1);
    int q;
    cin >> q;
    segTree[1].lazy = 1;
    while(q--){
        int op, a;
        cin >> op >> a;
        if(op == 1){
            if(in[a] == out[a]) continue;
            update(1, 0, n - 1, in[a] + 1, out[a], 1);
        }
        else if(op == 2){
            if(in[a] == out[a]) continue;
            update(1, 0, n - 1, in[a] + 1, out[a], 0);
        }
        else if(op == 3){
            if(in[a] == out[a]) cout << 0 << "\n";
            else cout << query(1, 0, n - 1, in[a] + 1, out[a]) << "\n";
        }
    }
}
