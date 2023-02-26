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
    int n, m;
    cin >> n >> m;
    vector<vi> dp(n + 1, vi(m + 1, (int)1e9));
    int k;
    cin >> k;
    vector<vi> X(n + 1, vi(m + 1));
    vector<vi> Y(n + 1, vi(m + 1));
    for(int i{0}; i < k; ++i){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for(int j{y1}; j <= y2; ++j){
            X[x1][j]++;
        }
        for(int j{x1}; j <= x2; ++j){
            Y[j][y1]++;
        }
    }
    dp[1][1] = X[1][1];
    for(int i{1}; i <= n; ++i){
        for(int j{1}; j <= m; ++j){
            if(i == 1 && j == 1) continue;
            dp[i][j] = min(dp[i - 1][j] + X[i][j], dp[i][j - 1] + Y[i][j]);
        }
    }
    cout << dp[n][m];
}
