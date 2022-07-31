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

int main() {
	fastio;
	int n, m, q;
    cin >> n >> m >> q;
    vector<vi> board(n, vi(m));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            cin >> board[i][j];
        }
    }
    while(q--){
        int a, b, c;
        cin >> a >> b >> c;
        for(int i{0}; i  < n; ++i){
            if((i + 1) % a == 0){
                if(b == 0){
                    rotate(board[i].rbegin(), board[i].rbegin() + c, board[i].rend());
                }
                else{
                    rotate(board[i].begin(), board[i].begin() + c, board[i].end());
                }
            }
        }
        int xx[]{-1,0,1,0};
        int yy[]{0,1,0,-1};
        vector<vi> ch(n, vi(m));
        bool flag = false;
        for(int i{0}; i < n; ++i){
            for(int j{0}; j < m; ++j){
                if(board[i][j] != 0 && ch[i][j] == 0){
                    ch[i][j] = 1;
                    queue<pi> Q;
                    Q.push({i, j});
                    vp vec;
                    while(!Q.empty()){
                        int x{Q.front().first};
                        int y{Q.front().second};
                        Q.pop();
                        vec.push_back({x, y});
                        for(int dir{0}; dir < 4; ++dir){
                            int nx{x + xx[dir]};
                            int ny = (y + yy[dir] + m) % m;                
                            if(nx < 0 || nx > n - 1) continue;
                            if(board[nx][ny] == board[x][y] && ch[nx][ny] == 0){
                                ch[nx][ny] = 1;
                                Q.push({nx, ny});
                            }
                        }
                    }
                    if(vec.size() >= 2){
                        for(auto& c : vec){
                            board[c.first][c.second] = 0;
                        }
                        flag = true;
                    }
                }
            }
        }
        if(!flag){
            int sum{0};
            int cnt{0};
            for(int i{0}; i < n; ++i){
                for(int j{0}; j < m; ++j){
                    if(board[i][j] != 0){
                        sum += board[i][j];
                        cnt++;
                    }
                }
            }
            double d = 1.0 * sum / cnt;
            for(int i{0}; i < n; ++i){
                for(int j{0}; j < m; ++j){
                    if(board[i][j] != 0){
                        if(board[i][j] > d) board[i][j]--;
                        else if(board[i][j] < d) board[i][j]++;
                    }
                }
            }
        }
    }
    int sum{0};
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            sum += board[i][j];
        }
    }
    cout << sum;
}

