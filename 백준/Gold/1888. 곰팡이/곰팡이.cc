// 2022-08-16
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

int main() {
	fastio;
    int n, m;
    cin >> n >> m;
    vector<vi> board(n, vi(m));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            char c;
            cin >> c;
            board[i][j] = c - '0';
        }
    }
    int xx[]{-1,0,1,0};
    int yy[]{0,1,0,-1};
    int time{0};
    while(1){
        vector<vi> ch(n, vi(m));
        int cnt{0};
        for(int i{0}; i < n; ++i){
            for(int j{0}; j < m; ++j){
                if(ch[i][j] == 0 && board[i][j] > 0){
                    ch[i][j] = 1;
                    cnt++;
                    queue<pi> Q;
                    Q.push({i, j});
                    while(!Q.empty()){
                        int x{Q.front().first};
                        int y{Q.front().second};
                        Q.pop();
                        for(int dir{0}; dir < 4; ++dir){
                            int nx{x + xx[dir]};
                            int ny{y + yy[dir]};
                            if(nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1) continue;
                            if(ch[nx][ny] == 0 && board[nx][ny]){
                                ch[nx][ny] = 1;
                                Q.push({nx, ny});
                            }
                        }
                    }
                }
            }
        }
        if(cnt == 1){
            cout << time;
            return 0;
        }
        for(int i{0}; i < n; ++i){
            for(int j{0}; j < m; ++j){
                ch[i][j] = 0;
            }
        }
        vector<vi> ch2(n, vi(m));
        for(int i{0}; i < n; ++i){
            for(int j{0}; j < m; ++j){
                if(ch[i][j] == 0 && board[i][j] > 0){
                    ch[i][j] = 1;
                    for(int x{max(0, i - board[i][j])}; x <= min(n - 1, i + board[i][j]); ++x){
                        for(int y{max(0, j - board[i][j])}; y <= min(m - 1, j + board[i][j]); ++y){
                            ch2[x][y] = max(ch2[x][y], board[i][j]);
                        }
                    }
                }
            }
        }
        board = ch2;
        time++;
    }
}