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
	int v, lazy;
};

vector<st> segTree(400001);
vector<int> vec(100001);

int init(int node, int l, int r) {
	if (l == r) return segTree[node].v = vec[l];
	int m{ (l + r) / 2 };
	return segTree[node].v = init(node * 2, l, m) ^ init(node * 2 + 1, m + 1, r);
}

void update(int node, int l, int r, int s, int e, int diff) {
	if (segTree[node].lazy != 0) {
		if((r - l + 1) & 1) segTree[node].v ^= segTree[node].lazy;
		if (l != r) {
			segTree[node * 2].lazy ^= segTree[node].lazy;
			segTree[node * 2 + 1].lazy ^= segTree[node].lazy;
		}
		segTree[node].lazy = 0;
	}
	if (e < l || r < s) return;
	if (s <= l && r <= e) {
        if((r - l + 1) & 1) segTree[node].v ^= diff;
		if (l != r) {
			segTree[node * 2].lazy ^= diff;
			segTree[node * 2 + 1].lazy ^= diff;
		}
		return;
	}
	int m{ (l + r) / 2 };
	update(node * 2, l, m, s, e, diff);
	update(node * 2 + 1, m + 1, r, s, e, diff);
	segTree[node].v = segTree[node * 2].v ^ segTree[node * 2 + 1].v;
}

int query(int node, int l, int r, int s, int e) {
	if (segTree[node].lazy != 0) {
        if((r - l + 1) & 1) segTree[node].v ^= segTree[node].lazy;
		if (l != r) {
			segTree[node * 2].lazy ^= segTree[node].lazy;
			segTree[node * 2 + 1].lazy ^= segTree[node].lazy;
		}
		segTree[node].lazy = 0;
	}
	if (e < l || r < s) return 0;
	if (s <= l && r <= e) return segTree[node].v;
	int m{ (l + r) / 2 };
	return query(node * 2, l, m, s, e) ^ query(node * 2 + 1, m + 1, r, s, e);
}

int main(){
	fastio;
    int n, q;
    cin >> n >> q;
    vector<vi> g(n + 1);
    for(int i{0}; i < n - 1; ++i){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vi A(n + 1);
    for(int i{1}; i <= n; ++i){
        cin >> A[i];
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
    for(int i{1}; i <= n; ++i){
        vec[in[i]] = A[i];
    }
    init(1, 0, n - 1);
    while(q--){
        int op, a, b;
        cin >> op;
        if(op == 1){
            cin >> a;
            cout << query(1, 0, n - 1, in[a], out[a]) << "\n";
        }
        else if(op == 2){
            cin >> a >> b;
            update(1, 0, n - 1, in[a], out[a], b);
        }
    }
}
