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
#define MOD 1000000000
typedef long long ll;
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<vi> dp(k + 1, vi(n + 1));
    for(int j{0}; j <= n; ++j) dp[0][j] = 1;
    for(int i{1}; i <= k; ++i){
        for(int j{0}; j <= n; ++j){
            dp[i][j] += dp[i - 1][j];
            if(i < k && j > 0) dp[i][j] += dp[i][j - 1];
            dp[i][j] %= MOD;
        }
    }
    cout << dp[k][n] << "\n";
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
