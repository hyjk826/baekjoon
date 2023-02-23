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
	vector<vl> lookup;
	SparseTable(vl& arr){
		lookup.resize((int)arr.size(), vl(20));
		int n = (int)arr.size();
		for (int i = 0; i < n; i++)
			lookup[i][0] = arr[i];
		for (int j = 1; (1 << j) <= n; j++) {
			for (int i = 0; (i + (1 << j) - 1) < n; i++) {
				lookup[i][j] = max(lookup[i][j - 1], lookup[i + (1 << (j - 1))][j - 1]);
			}
		}
	}
	ll query(int L, int R){
		int j = (int)log2(R - L + 1);
		return max(lookup[L][j], lookup[R - (1 << j) + 1][j]);
	}
};

int main(){
	fastio;
    int n, k;
    cin >> n >> k;
    vl A(n + 1), B(n + 1);
    for(int i{1}; i <= n; ++i){
        cin >> A[i];
    }
    for(int i{1}; i <= n; ++i){
        cin >> B[i];
    }
    for(int i{1}; i <= n; ++i){
        A.push_back(A[i]);
        B.push_back(B[i]);
    }
    for(int i{1}; i <= 2 * n; ++i){
        A[i] += A[i - 1];
        B[i] += B[i - 1];
    }
    SparseTable sp(A);
    ll ans{-LLONG_MAX};
    for(int i{1}; i <= n; ++i){
        int idx = lower_bound(B.begin(), B.end(), B[i - 1] + k) - B.begin();
        ans = max(ans, sp.query(idx, i - 1 + n) - A[i - 1]);
    }
    cout << ans;
}
