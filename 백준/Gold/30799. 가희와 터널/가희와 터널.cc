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
#define MAX 2147000000
#define MOD 998244353
typedef long long ll;
using namespace std;

int dp[60000][8][8];

void solve(){
	int n;
    cin >> n;
    dp[0][0][1] = 1;
    for(int i{1}; i <= n; ++i){
        for(int j{1}; j <= 7; ++j){
            for(int a{0}; a <= 7; ++a){
                for(int b{1}; b <= 7; ++b){
                    if(a == j - 1) {
                        dp[i][j][j] += dp[i - 1][a][b];
                        dp[i][j][j] %= MOD;
                    }
                    else {
                        dp[i][a][j] += dp[i - 1][a][b];
                        dp[i][a][j] %= MOD;
                    }

                }
            }
        }
    }
    int ans{0};
    for(int i{1}; i <= 7; ++i){
        ans += dp[n][7][i];
        ans %= MOD;
    }
    cout << ans << "\n";
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
