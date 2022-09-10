// 2022-09-10
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define vs vector<string>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

vector<vc> board(100, vc(100));
int n;
int xx[]{-1,0,1,0};
int yy[]{0,1,0,-1};

int bfs(){
    vector<vi> ch(n, vi(n));
    int r{0};
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < n; ++j){
            if(ch[i][j] == 0){
                ch[i][j] = 1;
                queue<pi> Q;
                Q.push({i, j});
                r++;
                while(!Q.empty()){
                    int x{Q.front().first};
                    int y{Q.front().second};
                    Q.pop();
                    for(int dir{0}; dir < 4; ++dir){
                        int nx{x + xx[dir]};
                        int ny{y + yy[dir]};
                        if(nx < 0 || nx > n - 1 || ny < 0 || ny > n - 1) continue;
                        if(board[nx][ny] == board[i][j] && ch[nx][ny] == 0){
                            ch[nx][ny] = 1;
                            Q.push({nx, ny});
                        }
                    }
                }
            }
        }
    }   
    return r;
}
int main(){
    fastio;
    cin >> n;
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < n; ++j){
            cin >> board[i][j];
        }
    }
    cout << bfs() << " ";
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < n; ++j){
            if(board[i][j] == 'G') board[i][j] = 'R';
        }
    }
    cout << bfs();
}