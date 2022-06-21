// 2022-06-22
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

bool f(int a, int b, string& str, vector<vi>& dp) {
    if (a > (int)str.size() - 1 || b < 0) return 1;
    if (dp[a][b] != -1) return dp[a][b];
    if (a > b) return dp[a][b] = 1;
    if (str[a] == str[b]) return dp[a][b] = f(a + 1, b - 1, str, dp);
    else return dp[a][b] = 0;
}

int main() {
    fastio;
    string str;
    cin >> str;
    int n = (int)str.size();
    vi ans(n, MAX);
    vector<vi> dp(n, vi(n, -1));
    for (int i{ 0 }; i < n; ++i) {
        for (int j{ i }; j < n; ++j) {
            dp[i][j] = f(i, j, str, dp);
        }
    }
    for (int i{ 0 }; i < n; ++i) {
        for (int j{ 0 }; j <= i; ++j) {
            if (dp[j][i]) {
                if (j == 0) ans[i] = min(ans[i], 1);
                else ans[i] = min(ans[i], ans[j - 1] + 1);
            }
        }
    }
    cout << ans[n - 1];
}