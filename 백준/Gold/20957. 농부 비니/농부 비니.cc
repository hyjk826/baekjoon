// 2022-11-28
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


int dp[10001][7][7];

int main() {
	fastio;
    for(int i{1}; i <= 9; ++i){
        dp[1][i % 7][i % 7]++;
    }
    for(int i{1}; i < 10000; ++i){
        for(int j{0}; j < 7; ++j){
            for(int k{0}; k < 7; ++k){
                for(int a{0}; a <= 9; ++a){
                    dp[i + 1][(j + a) % 7][(k * a) % 7] += dp[i][j][k];
                    dp[i + 1][(j + a) % 7][(k * a) % 7] %= MOD;
                }
            }
        }
    }

	int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << dp[n][0][0] << "\n";
    }
}
	
