// 2022-12-08
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
    vector<vc> board(n, vc(m));
    int sx, sy, tx, ty;
    sx = -1;
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            cin >> board[i][j];
            if(i == 0 || j == 0 || i == n - 1 || j == m - 1){
                if(board[i][j] == '+') continue;
                if(sx == -1){
                    sx = i; sy = j;
                }
                else{
                    tx = i; ty = j;
                }
            }
        }
    }
    vector<vi> ch(n, vi(m, -1));
    queue<pi> Q;
    Q.push({sx, sy});
    ch[sx][sy] = 0;
    int xx[]{-1,0,1,0};
    int yy[]{0,1,0,-1};
    while(!Q.empty()){
        int x{Q.front().first};
        int y{Q.front().second};
        Q.pop();
        for(int dir{0}; dir < 4; ++dir){
            int nx{x + xx[dir]};
            int ny{y + yy[dir]};
            if(nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1 || board[nx][ny] == '+' || ch[nx][ny] != -1) continue;
            ch[nx][ny] = dir;
            Q.push({nx, ny});
        }
    }
    int x = tx;
    int y = ty;
    while(!(x == sx && y == sy)){
        board[x][y] = 'S';
        int dir = ch[x][y];
        x -= xx[dir];
        y -= yy[dir];
    }
    board[sx][sy] = 'S';
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            if(board[i][j] == 'S') board[i][j] = '.';
            else if(board[i][j] == '.') board[i][j] = '@';
            cout << board[i][j];
        }
        cout << "\n";
    }
}
	
