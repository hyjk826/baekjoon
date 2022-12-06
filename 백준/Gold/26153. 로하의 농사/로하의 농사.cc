// 2022-12-07
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

int n, m;
int sx, sy, p;
vector<vi> board(50, vi(50));
vector<vi> ch(50, vi(50));
int ans{0};
int xx[]{-1,0,1,0};
int yy[]{0,1,0,-1};

void dfs(int x, int y, int d, int sum, int cnt){
    if(cnt > p) return;
    ans = max(ans, sum);
    for(int dir{0}; dir < 4; ++dir){
        int nx{x + xx[dir]};
        int ny{y + yy[dir]};
        if(nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1) continue;
        if(ch[nx][ny]) continue;
        if(d % 2 != dir % 2){
            ch[nx][ny] = 1;
            dfs(nx, ny, dir % 2, sum + board[nx][ny], cnt + 2);
            ch[nx][ny] = 0;
        }
        else {
            ch[nx][ny] = 1;
            dfs(nx, ny, dir % 2, sum + board[nx][ny], cnt + 1);
            ch[nx][ny] = 0;
        }
    }
}

int main() {
	fastio;
	cin >> n >> m;
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            cin >> board[i][j];
        }
    }
    cin >> sx >> sy >> p;
    ch[sx][sy] = 1;
    ans = board[sx][sy];
    for(int dir{0}; dir < 4; ++dir){
        int nx{sx + xx[dir]};
        int ny{sy + yy[dir]};
        if(nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1) continue;        
        ch[nx][ny] = 1;
        dfs(nx, ny, dir % 2, board[sx][sy] + board[nx][ny], 1);
        ch[nx][ny] = 0;
    }
    cout << ans;
}
	
