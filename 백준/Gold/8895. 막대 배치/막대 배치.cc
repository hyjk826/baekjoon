// 2023-01-16
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

ll dp[21][21][21];

int main(){
	fastio;
    dp[1][1][1] = 1;
    for(int i{1}; i < 20; ++i){
        for(int j{1}; j <= i; ++j){
            for(int k{1}; k <= i; ++k){
                dp[i + 1][j + 1][k] += dp[i][j][k];
                dp[i + 1][j][k + 1] += dp[i][j][k];
                dp[i + 1][j][k] += 1LL * dp[i][j][k] * (i - 1);
            }
        }
    }
    int t;
    cin >> t;
    while(t--){
        int n, l, r;
        cin >> n >> l >> r;
        cout << dp[n][l][r] << "\n";
    }
}