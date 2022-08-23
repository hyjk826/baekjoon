// 2022-08-23
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
#define MOD 1000000007
using namespace std;

int main() {
    fastio;
    int n, w;
    cin >> n >> w;
    vector<vector<vi> > dp(n + 1, vector<vi>(w + 1, vi(2)));
    vi vec(n + 1);
    for (int i{ 1 }; i <= n; ++i) {
        cin >> vec[i];
    }
    for (int i{ 1 }; i <= n; ++i) {
        for (int j{ 0 }; j <= w; ++j) {
            if (vec[i] == 1) {
                if (j == 0) dp[i][0][0] = dp[i - 1][0][0] + 1;
                else {
                    dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j - 1][1]) + 1;
                    dp[i][j][1] = dp[i - 1][j][1];
                }
            }
            else {
                if (j == 0) dp[i][0][0] = dp[i - 1][0][0];                   
                else {
                    dp[i][j][1] = max(dp[i - 1][j - 1][0], dp[i - 1][j][1]) + 1;
                    dp[i][j][0] = dp[i - 1][j][0];
                }
            }
        }
    }
    int ans{ 0 };
    for (int i{ 0 }; i <= w; ++i) {
        for (int j{ 0 }; j < 2; ++j) {
            ans = max(ans, dp[n][i][j]);
        }
    }
    cout << ans;
}
