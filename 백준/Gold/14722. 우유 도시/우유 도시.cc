// 2022-10-20
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

int dp[1001][1001][3]{};


int main() {
	fastio;
    int n;
    cin >> n;
    vector<vi> board(n, vi(n));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < n; ++j){
            cin >> board[i][j];
            if(board[i][j] == 0){
                dp[i][j][0] = 1;
            }
        }
    }
    int ans{0};
    int xx[]{-1,0};
    int yy[]{0,-1};
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < n; ++j){
            for(int k{0}; k < 3; ++k){
                if(i > 0) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k]);
                if(j > 0) dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k]);
            }
            for(int dir{0}; dir < 2; ++dir){
                int px{i + xx[dir]};
                int py{j + yy[dir]};
                if(px < 0 || py < 0) continue;
                int a = (board[i][j] + 2) % 3;
                if(dp[px][py][a] == 0) continue;
                dp[i][j][board[i][j]] = max(dp[i][j][board[i][j]], dp[px][py][a] + 1);
            }
        }
    }
    ans = max({dp[n - 1][n - 1][0], dp[n - 1][n - 1][1], dp[n - 1][n - 1][2]});
    cout << ans;
}
	

