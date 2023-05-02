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

int main(){
	fastio;
    int n, k;
    cin >> n >> k;
    vector<vl> dp(n + 1, vl(k + 1));
    vector<vl> sum(n + 1, vl(k + 1));
    for(int i{1}; i <= k; ++i){
        dp[1][i] = sum[1][i] = 1;
        sum[1][i] += sum[1][i - 1];
    }
    for(int i{2}; i <= n; ++i){
        for(int j{1}; j <= k; ++j){
            dp[i][j] += sum[i - 1][j];
            dp[i][j] += sum[i - 1][k] - sum[i - 1][j];
            for(int a{j * 2}; a <= k; a += j){
                dp[i][j] = (dp[i][j] - dp[i - 1][a] + MOD) % MOD;
            }
            sum[i][j] = dp[i][j];
            sum[i][j] += sum[i][j - 1];
            sum[i][j] %= MOD;
        }
    }
    cout << sum[n][k];
}
