// 2022-08-31
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

vector<vector<vi> > dp(1000, vector<vi>(1000, vi(3, -MAX)));
vector<vi> board(1000, vi(1000));
vector<vi> ch(1000, vi(1000));
int xx[]{0, 0, 1};
int yy[]{1, -1, 0};
int n, m;

int f(int x, int y, int d){
    if(x == n - 1 && y == m - 1) return board[x][y];
    if(dp[x][y][d] != -MAX) return dp[x][y][d];
    dp[x][y][d] = board[x][y];
    int mx{-MAX};
    for(int dir{0}; dir < 3; ++dir){
        int nx{x + xx[dir]};
        int ny{y + yy[dir]};
        if(nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1 || ch[nx][ny] == 1) continue;
        ch[nx][ny] = 1;
        mx = max(mx, f(nx, ny, dir));
        ch[nx][ny] = 0;
    }
    dp[x][y][d] += mx;
    return dp[x][y][d];
}


int main() {
	fastio;
    cin >> n >> m;
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            cin >> board[i][j];
        }
    }    
    ch[0][0] = 1;
    cout << f(0, 0, 0);
}

