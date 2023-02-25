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
    int n, m;
    cin >> n >> m;
    vector<vl> dp(n + 1, vl(m + 1));
    dp[1][1] = 1;
    for(int i{1}; i <= n; ++i){
        for(int j{1}; j <= m; ++j){
            if(i == 1 && j == 1) continue;
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] + dp[i - 1][j - 1];
            dp[i][j] %= MOD;
        }
    }
    cout << dp[n][m];
}
