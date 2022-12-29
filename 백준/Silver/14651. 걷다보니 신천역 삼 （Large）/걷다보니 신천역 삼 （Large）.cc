// 2022-12-30
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
#define MOD 1000000009
using namespace std;


int main(){
	fastio;
    int n;
    cin >> n;
    vector<vi> dp(n + 1, vi(3));
    dp[1][1] = dp[1][2] = 1;
    for(int i{1}; i < n; ++i){
        for(int j{0}; j < 3; ++j){
            for(int k{0}; k < 3; ++k){
                dp[i + 1][(j + k) % 3] += dp[i][j];
                dp[i + 1][(j + k) % 3] %= MOD;
            }
        }
    }
    cout << dp[n][0];
}
