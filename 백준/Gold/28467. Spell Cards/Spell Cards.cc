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

struct SparseTable{
	vector<vi> lookup;
	SparseTable(vi& arr){
		lookup.resize((int)arr.size(), vi(20));
		int n = (int)arr.size();
		for (int i = 0; i < n; i++)
			lookup[i][0] = arr[i];
		for (int j = 1; (1 << j) <= n; j++) {
			for (int i = 0; (i + (1 << j) - 1) < n; i++) {
				lookup[i][j] = max(lookup[i][j - 1], lookup[i + (1 << (j - 1))][j - 1]);
			}
		}
	}
	int query(int L, int R){
		int j = (int)log2(R - L + 1);
		return max(lookup[L][j], lookup[R - (1 << j) + 1][j]);
	}
};


void solve(){
	int n;
    cin >> n;
    vi vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    SparseTable sp(vec);
    vector<vl> dp(n, vl(n, -1));
    function<ll(int,int)> f = [&](int a, int b){
        if(dp[a][b] != -1) return dp[a][b];
        ll& ret = dp[a][b];
        ret = LLONG_MAX;
        if(a == b) return ret = 0LL;
        for(int j{a}; j < b; ++j){
            ret = min(ret, f(a, j) + f(j + 1, b) + sp.query(a, j) + sp.query(j + 1, b));
        }
        return ret;
    };
    cout << f(0, n - 1) << "\n";
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
