// 2023-01-12
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

int dp[101][101][101];

int main(){
	fastio;
    int n, l, r;
    cin >> n >> l >> r;
    dp[1][1][1] = 1;
    for(int i{2}; i <= n; ++i){
        for(int j{1}; j <= l; ++j){
            for(int k{1}; k <= r; ++k){
                dp[i][j][k] = (dp[i - 1][j - 1][k] + dp[i - 1][j][k - 1] + 1LL * dp[i - 1][j][k] * (i - 2)) % MOD;
            }
        }
    }
    cout << dp[n][l][r];
}
