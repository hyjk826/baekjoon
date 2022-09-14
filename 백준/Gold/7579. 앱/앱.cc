// 2022-09-14
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
#define ll long long
#define MAX 1000000000
#define MOD 1000000007
using namespace std;

int main() {
	fastio;
    int n, k;
    cin >> n >> k;
    vi A(n), B(n);
    for(int i{0}; i < n; ++i) cin >> A[i];
    for(int i{0}; i < n; ++i) cin >> B[i];
    vi dp(10001);
    for(int i{0}; i < n; ++i){
        for(int j{10000}; j >= B[i]; --j){
            dp[j] = max(dp[j], dp[j - B[i]] + A[i]);
        }
    }
    int ans{MAX};
    for(int i{0}; i <= 10000; ++i){
        if(dp[i] == MAX) continue;
        if(dp[i] >= k){
            cout << i;
            return 0;
        }
    }
}
	

