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
    int n;
    cin >> n;
    vi vec(n + 1);
    for(int i{1}; i <= n; ++i){
        cin >> vec[i];
    }
    vector<vi> dp(n + 1, vi(500001, -1));
    for(int i{1}; i <= 500000; ++i){
        dp[0][i] = -1;
    }
    dp[0][0] = 0;
    for(int i{1}; i <= n; ++i){
        for(int j{0}; j <= 500000; ++j){
            dp[i][j] = dp[i - 1][j];
            if(j + vec[i] <= 500000 && dp[i - 1][j + vec[i]] != -1){
                dp[i][j] = max(dp[i][j], dp[i - 1][j + vec[i]]);
            }
            if(j >= vec[i] && dp[i - 1][j - vec[i]] != -1){
                dp[i][j] = max(dp[i][j], dp[i - 1][j - vec[i]] + vec[i]);
            }
            if(j <= vec[i] && dp[i - 1][vec[i] - j] != -1){
                dp[i][j] = max(dp[i][j], dp[i - 1][vec[i] - j] + j);
            }
        }
    }
    if(dp[n][0] == 0) cout << -1;
    else cout << dp[n][0];
}
