// 2022-07-31
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

int ch[50][50][1 << 6]{};

struct st{
    int x, y, state, cnt;
};

int main() {
	fastio;
    int n, m;
    cin >> n >> m;
    vector<vc> board(n, vc(m));
    pi s;
    queue<st> Q;
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            cin >> board[i][j];
            if(board[i][j] == '0'){
                board[i][j] = '.';
                Q.push({i, j, 0, 0});
                ch[i][j][0] = 1;
            }
        }
    }
    int xx[]{-1,0,1,0};
    int yy[]{0,1,0,-1};
    while(!Q.empty()){
        int x{Q.front().x};
        int y{Q.front().y};
        int state{Q.front().state};
        int cnt{Q.front().cnt};
        if(board[x][y] == '1'){
            cout << cnt;
            return 0;
        }
        Q.pop();
        for(int dir{0}; dir < 4; ++dir){
            int nx{x + xx[dir]};
            int ny{y + yy[dir]};
            if(nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1) continue;
            if(board[nx][ny] == '.' && ch[nx][ny][state] == 0){
                ch[nx][ny][state] = 1;
                Q.push({nx, ny, state, cnt + 1});
            }
            else if('a' <= board[nx][ny] && board[nx][ny] <= 'z'){
                if(ch[nx][ny][state | (1 << (board[nx][ny] - 'a'))] == 1) continue;
                ch[nx][ny][state | (1 << (board[nx][ny] - 'a'))] = 1;
                Q.push({nx, ny, state | (1 << (board[nx][ny] - 'a')), cnt + 1});
            }
            else if('A' <= board[nx][ny] && board[nx][ny] <= 'Z' && ch[nx][ny][state] == 0){
                if(state >> (board[nx][ny] - 'A') & 1){
                    ch[nx][ny][state] = 1;
                    Q.push({nx, ny, state, cnt + 1});
                }
            }
            else if(board[nx][ny] == '1'){
                if(ch[nx][ny][state] == 0){
                    Q.push({nx, ny, state, cnt + 1});
                }
            }
        }
    }
    cout << -1;
}

