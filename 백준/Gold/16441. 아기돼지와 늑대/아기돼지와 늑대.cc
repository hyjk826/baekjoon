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

struct st{
    int x, y, d;
};

int main() {
	fastio;
	int n, m;
    cin >> n >> m;
    vector<vc> board(n, vc(m));
    vector<vector<vi> > ch(n, vector<vi>(m, vi(4)));
    queue<st> Q;
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            cin >> board[i][j];
            if(board[i][j] == 'W'){
                for(int k{0}; k < 4; ++k){
                    Q.push({i, j, k});
                    ch[i][j][k] = 1;
                }
            }
        }
    }
    int xx[]{-1,0,1,0};
    int yy[]{0,1,0,-1};
    while(!Q.empty()){
        int x{Q.front().x};
        int y{Q.front().y};
        int d{Q.front().d};
        Q.pop();
        if(board[x][y] == '.' || board[x][y] == 'W'){
            int nx{x + xx[d]};
            int ny{y + yy[d]};
            if(board[nx][ny] == '#') continue;
            if(board[nx][ny] == '.'){
                for(int k{0}; k < 4; ++k){
                    if(ch[nx][ny][k] == 0){
                        Q.push({nx, ny, k});
                        ch[nx][ny][k] = 1;
                    }
                }                
            }
            else if(board[nx][ny] == '+'){
                if(ch[nx][ny][d] == 0){
                    Q.push({nx, ny, d});
                    ch[nx][ny][d] = 1;
                }
            }
        }   
        else if(board[x][y] == '+'){
            int nx = x;
            int ny = y;
            while(board[nx][ny] == '+'){
                nx += xx[d];
                ny += yy[d];
            }
            if(board[nx][ny] == '.'){
                for(int k{0}; k < 4; ++k){
                    if(ch[nx][ny][k] == 0){
                        ch[nx][ny][k] = 1;
                        Q.push({nx, ny, k});
                    }
                }
            }
            else if(board[nx][ny] == '#'){
                nx -= xx[d];
                ny -= yy[d];
                for(int k{0}; k < 4; ++k){                    
                    if(ch[nx][ny][k] == 0){
                        ch[nx][ny][k] = 1;
                        Q.push({nx, ny, k});
                    }
                }
            }
        }
    }
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            if(board[i][j] == '.'){
                bool flag = true;
                for(int k{0}; k < 4; ++k){
                    flag &= (ch[i][j][k] == 0);
                }
                if(flag) board[i][j] = 'P';
            }
            cout << board[i][j];
        }
        cout << "\n";
    }
}
	
