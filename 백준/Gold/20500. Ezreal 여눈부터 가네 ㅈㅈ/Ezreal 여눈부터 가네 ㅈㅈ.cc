// 2022-10-15
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
#define MOD 1000000007
using namespace std;

int main() {
	fastio;
    int n;
    cin >> n;
    vector<vi> dp(n, vi(3));
    dp[0][0] = 1;
    for(int i{0}; i < n - 1; ++i){
        for(int j{0}; j < 3; ++j){
            dp[i + 1][(j + 1) % 3] += dp[i][j];
            dp[i + 1][(j + 1) % 3] %= MOD;
            dp[i + 1][(j + 5) % 3] += dp[i][j];
            dp[i + 1][(j + 5) % 3] %= MOD;
        }
    }
    cout << dp[n - 1][1];
}
	

