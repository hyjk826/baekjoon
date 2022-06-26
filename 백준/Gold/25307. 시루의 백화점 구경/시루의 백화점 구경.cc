// 2022-06-26
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

int main(){
    fastio;
    int n, m, k;
    cin >> n >> m >> k;
    vector<vi> board(n, vi(m));
    int cx, cy, ax, ay;
    vector<pi> block;
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            cin >> board[i][j];
            if(board[i][j] == 3) block.push_back({i, j});
            else if(board[i][j] == 4){
                ax = i;
                ay = j;
                board[i][j] = 1;
            }
            else if(board[i][j] == 2){
                cx = i;
                cy = j;
                board[i][j] = 0;
            }
            else if(board[i][j] == 1){
                board[i][j] = -1;
            }
        }
    }
    queue<pi> Q;
    int xx[]{-1,0,1,0};
    int yy[]{0,1,0,-1};
    for(int dir{0}; dir < 4; ++dir){
        int nx = ax + xx[dir];
        int ny = ay + yy[dir];
        if(nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1) continue;
        if(board[nx][ny] == 0){
            board[nx][ny] = 2;
            Q.push({nx, ny});
        }
    }
    while(!Q.empty()){
        int x{Q.front().first};
        int y{Q.front().second};
        Q.pop();
        if(x == cx && y == cy){
            cout << board[x][y] - 1;
            return 0;
        }
        for(int dir{0}; dir < 4; ++dir){
            int nx{x + xx[dir]};
            int ny{y + yy[dir]};
            if(nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1) continue;
            if(board[nx][ny] == 0){
                bool flag = true;
                for(auto& i : block){
                    if(abs(i.first - nx) + abs(i.second - ny) <= k){
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    board[nx][ny] = board[x][y] + 1;
                    Q.push({nx, ny});
                }
            }
        }
    }
    cout << -1;
}
