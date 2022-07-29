// 2022-07-29
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
#define MAX 2147000000
#define MOD 1000000003
using namespace std;

int main() {
	fastio;
    int n, k;
    cin >> n >> k;
    vector<vi> dp(n + 1, vi(k + 1));
    for(int i{0}; i <= n; ++i){
        dp[i][0] = 1;
        dp[i][1] = i;
    }
    for(int i{2}; i <= n; ++i){
        for(int j{2}; j <= min((i + 1) / 2, k); ++j){
            dp[i][j] = dp[i - 2][j - 1] + dp[i - 1][j];
            dp[i][j] %= MOD;
        }
    }
    cout << (dp[n - 3][k - 1] + dp[n - 1][k]) % MOD;
}

