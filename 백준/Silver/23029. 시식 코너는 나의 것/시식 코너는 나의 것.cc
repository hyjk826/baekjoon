// 2022-11-20
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

int main() {
	fastio;
    int n;
    cin >> n;
    vi vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    vector<vi> dp(n + 1, vi(3));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < 3; ++j){
            if(j == 0){
                dp[i + 1][0] = max(dp[i + 1][0], dp[i][j]);
                dp[i + 1][1] = max(dp[i + 1][1], dp[i][j] + vec[i]);
            }
            else if(j == 1){
                dp[i + 1][0] = max(dp[i + 1][0], dp[i][j]);
                dp[i + 1][2] = max(dp[i + 1][2], dp[i][j] + vec[i] / 2);
            }
            else{
                dp[i + 1][0] = max(dp[i + 1][0], dp[i][j]);
            }
        }
    }
    int ans{0};
    for(int i{1}; i <= n; ++i){
        for(int j{0}; j < 3; ++j){
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans;
}
	

