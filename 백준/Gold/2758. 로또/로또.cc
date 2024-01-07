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
#define MOD 1000000007
typedef long long ll;
using namespace std;

void solve(){
	int n, m;
    cin >> n >> m;
    vector<vl> dp(m + 1, vl(n + 1));
    for(int i{1}; i <= m; ++i) dp[i][1] = 1;
    for(int i{1}; i <= m; ++i){
        for(int j{2}; j <= n; ++j){
            dp[i][j] += dp[i / 2][j - 1];            
        }
        for(int j{1}; j <= n; ++j) dp[i][j] += dp[i - 1][j];
    }
    cout << dp[m][n] << "\n";
}

int main(){
	fastio;
	int T;
	cin >> T;
	while(T--){
		solve();
	}
}
