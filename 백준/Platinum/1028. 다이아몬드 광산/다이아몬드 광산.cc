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

int dp[750][750][4];
int xx[]{-1,-1,1,1};
int yy[]{-1,1,-1,1};
char board[750][750];
int n, m;

int f(int x, int y, int dir){
    if(x < 0 || x > n - 1 || y < 0 || y > m - 1) return 0;
    if(dp[x][y][dir] != -1) return dp[x][y][dir];
    if(board[x][y] == '0') return dp[x][y][dir] = 0;
    return dp[x][y][dir] = f(x + xx[dir], y + yy[dir], dir) + 1;
}

int main(){
	fastio;    
    cin >> n >> m;
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            cin >> board[i][j];
            for(int dir{0}; dir < 4; ++dir){
                dp[i][j][dir] = -1;
            }
        }
    }    
    int ans{0};
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            if(board[i][j] == '0') continue;
            ans = max(ans, 1);
            for(int k{min(f(i, j, 1), f(i, j, 3))}; k >= 1; --k){
                if(f(i, j + 2 * k, 0) >= k + 1 && f(i, j + 2 * k, 2) >= k + 1){
                    ans = max(ans, k + 1); break;
                }
            }
        }
    }
    cout << ans;
}
