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

int dp[1002][101][101]; // num, 일수, 독

void solve(){
    memset(dp, -1, sizeof(dp));
	int n, m;
    cin >> n >> m;
    int a, b, c;
    cin >> a >> b >> c;
    dp[0][0][c] = 0;
    for(int i{1}; i <= n; ++i){
        int x, y;
        cin >> x >> y;
        for(int j{0}; j <= m; ++j){
            for(int k{0}; k <= a; ++k){
                dp[i][j][k] = dp[i - 1][j][k];
            }
        }
        for(int j{0}; j <= m - 1; ++j){
            for(int k{0}; k <= a; ++k){
                dp[i][j + 1][max(0, k - b)] = max(dp[i][j + 1][max(0, k - b)], dp[i][j][k]);
            }
        }
        for(int j{m - 1}; j >= 0; --j){
            for(int k{0}; k <= a; ++k){
                if(dp[i][j][k] == -1 || k + x > a) continue;
                dp[i][j + 1][max(0, k + x - b)] = max(dp[i][j + 1][max(0, k + x - b)], dp[i][j][k] + y);
            }
        }
    }
    int ans{0};
    for(int i{0}; i <= n; ++i){
        for(int j{0}; j <= m; ++j){
            for(int k{0}; k <= a; ++k){
                ans = max(ans, dp[i][j][k]);
            }
        }
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
