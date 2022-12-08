// 2022-12-08
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

int main() {
	fastio;
	int n;
    cin >> n;
    vector<vi> dp(n + 1, vi(5));
    dp[1][0] = dp[1][1] = dp[1][2] = dp[1][3] = dp[1][4] = 1;
    for(int i{2}; i <= n; ++i){
        for(int j{0}; j < 5; ++j){
            if(j == 0){
                for(int k{1}; k <= 4; ++k){
                    dp[i][j] += dp[i - 1][k];
                    dp[i][j] %= MOD;
                }
            }
            else{
                dp[i][j] += dp[i - 1][0];
                dp[i][j] %= MOD;
                for(int k{1}; k <= 4; ++k){
                    if(abs(k - j) <= 1) continue;
                    dp[i][j] += dp[i - 1][k];
                    dp[i][j] %= MOD;
                }
            }
        }
    }
    int ans{0};
    for(int j{0}; j < 5; ++j){
        ans += dp[n][j];
        ans %= MOD;
    }
    cout << ans;
}
	
