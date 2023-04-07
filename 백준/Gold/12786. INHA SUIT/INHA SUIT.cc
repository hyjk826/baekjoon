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
    int n, k;
    cin >> n >> k;
    vector<vi> hole(n + 1);
    vector<vi> dp(n + 1);
    dp[0].push_back(0);
    hole[0].push_back(1);
    for(int i{1}; i <= n; ++i){
        int a;
        cin >> a;
        hole[i].resize(a);
        dp[i].resize(a, MAX);
        for(int j{0}; j < a; ++j){
            cin >> hole[i][j];
            for(int b{0}; b < (int)hole[i - 1].size(); ++b){
                if(hole[i - 1][b] == hole[i][j]){
                    dp[i][j] = min(dp[i][j], dp[i - 1][b]);
                }
                if(hole[i - 1][b] == hole[i][j] - 1){
                    dp[i][j] = min(dp[i][j], dp[i - 1][b]);
                }
                if(hole[i - 1][b] == hole[i][j] + 1){
                    dp[i][j] = min(dp[i][j], dp[i - 1][b]);
                }
                if(min(20, hole[i - 1][b] * 2) == hole[i][j]){
                    dp[i][j] = min(dp[i][j], dp[i - 1][b]);
                }
                if(dp[i - 1][b] < k) dp[i][j] = min(dp[i][j], dp[i - 1][b] + 1);
            }
        }        
    }
    int ans = *min_element(dp[n].begin(), dp[n].end());
    if(ans == MAX) cout << -1;
    else cout << ans;
}
