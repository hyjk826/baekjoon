// 2022-12-14
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
    int n, m;
    cin >> n >> m;
    vector<vi> board(n, vi(m));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            cin >> board[i][j];
        }
    }
    vi yy = {1, 0, -1};
    vector<vector<vi> > dp(n, vector<vi>(m, vi(3)));
    for(int j{0}; j < m; ++j){
        for(int i{0}; i < 3; ++i){
            dp[0][j][i] = board[0][j];
        }
    }
    for(int i{1}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            for(int k{0}; k < 3; ++k){
                int ny = j + yy[k];
                int mn{(int)1e9};
                if(ny < 0 || ny > m - 1) {
                    dp[i][j][k] = (int)1e9;
                    continue;
                }
                for(int a{0}; a < 3; ++a){
                    if(a == k) continue;
                    mn = min(mn, dp[i - 1][ny][a]);
                }
                dp[i][j][k] = board[i][j] + mn;
            }
        }
    }
    int ans{MAX};
    for(int j{0}; j < m; ++j){
        for(int k{0}; k < 3; ++k){
            ans = min(ans, dp[n - 1][j][k]);
        }
    }
    cout << ans;
}
	
