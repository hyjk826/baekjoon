// 2022-07-25
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
#define MOD 1000000009
using namespace std;

int main() {
	fastio;
    vector<vi> dp(100001, vi(4));
    dp[1][1] = dp[2][2] = dp[3][3] = 1;
    for(int i{2}; i <= 100000; ++i){
        for(int j{1}; j <= 3; ++j){
            if(i <= j) continue;
            for(int k{1}; k <= 3; ++k){
                if(k == j) continue;
                dp[i][j] += dp[i - j][k];
                dp[i][j] %= MOD;
            }
        }
    }
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << ((dp[n][1] + dp[n][2]) % MOD + dp[n][3]) % MOD << "\n";
    }
}

