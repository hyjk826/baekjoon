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

vector<st> segTree(2000001);
vector<ll> vec(500001);

ll init(int node, int l, int r) {
	if (l == r) return segTree[node].v = vec[l];
	int m{ (l + r) / 2 };
	return segTree[node].v = init(node * 2, l, m) + init(node * 2 + 1, m + 1, r);
}

void update(int node, int l, int r, int s, int e, ll diff) {
	if (segTree[node].lazy != 0) {
		segTree[node].v += segTree[node].lazy * (ll)(r - l + 1);
		if (l != r) {
			segTree[node * 2].lazy += segTree[node].lazy;
			segTree[node * 2 + 1].lazy += segTree[node].lazy;
		}
		segTree[node].lazy = 0;
	}
	if (e < l || r < s) return;
	if (s <= l && r <= e) {
		segTree[node].v += diff * (ll)(r-l+1);
		if (l != r) {
			segTree[node * 2].lazy += diff;
			segTree[node * 2 + 1].lazy += diff;
		}
		return;
	}
	int m{ (l + r) / 2 };
	update(node * 2, l, m, s, e, diff);
	update(node * 2 + 1, m + 1, r, s, e, diff);
	segTree[node].v = segTree[node * 2].v + segTree[node * 2 + 1].v;
}

ll sum(int node, int l, int r, int s, int e) {
	if (segTree[node].lazy != 0) {
		segTree[node].v += segTree[node].lazy * (ll)(r - l + 1);
		if (l != r) {
			segTree[node * 2].lazy += segTree[node].lazy;
			segTree[node * 2 + 1].lazy += segTree[node].lazy;
		}
		segTree[node].lazy = 0;
	}
	if (e < l || r < s) return 0;
	if (s <= l && r <= e) return segTree[node].v;
	int m{ (l + r) / 2 };
	return sum(node * 2, l, m, s, e) + sum(node * 2 + 1, m + 1, r, s, e);
}


int main(){
	fastio;
    int n, m;
    cin >> n >> m;
    vi in(n + 1), out(n + 1);
    vector<vi> g(n + 1);
    for(int i{1}; i <= n; ++i){
        cin >> vec[i];
        if(i > 1){
            int a;
            cin >> a;
            g[a].push_back(i);
        }
    }
    int cnt{-1};
    function<void(int)> dfs = [&](int cur){
        in[cur] = ++cnt;
        for(auto& i : g[cur]){
            dfs(i);
        }
        out[cur] = cnt;
    };
    dfs(1);
    for(int i{1}; i <= n; ++i){
        update(1, 0, n - 1, in[i], in[i], vec[i]);
    }
    for(int i{0}; i < m; ++i){
        char op;
        cin >> op;
        if(op == 'p'){
            int a, b;
            cin >> a >> b;
            if(in[a] != out[a]){
                update(1, 0, n - 1, in[a] + 1, out[a], b);
            }
        }
        else{
            int a;
            cin >> a;
            cout << sum(1, 0, n - 1, in[a], in[a]) << "\n";
        }
    }
}
