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

int dist[100][100][100][3]{};

struct st{
    int x, y, cur, state;
};


void solve(){
    int n;
    cin >> n;
    vector<vi> board(n, vi(n));
    int sx, sy;
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < n; ++j){
            cin >> board[i][j];
            if(board[i][j] == 1) sx = i, sy = j;
        }
    }
    memset(dist, -1, sizeof(dist));
    queue<st> Q;
    for(int i{0}; i < 3; ++i){
        Q.push({sx, sy, 0, i});
        dist[sx][sy][0][i] = 0;
    }
    int xx1[]{-2,-2,-1,-1,1,1,2,2};
    int yy1[]{-1,1,-2,2,-2,2,-1,1};
    int xx2[]{-1,-1,1,1};
    int yy2[]{-1,1,-1,1};
    int xx3[]{-1,0,1,0};
    int yy3[]{0,1,0,-1}; 
    while(!Q.empty()){
        int x{Q.front().x};
        int y{Q.front().y};
        int cur{Q.front().cur};
        int state{Q.front().state};
        Q.pop();
        int A = dist[x][y][cur][state];
        if(board[x][y] == cur + 1) cur++;
        if(cur == n * n){
            cout << A; return;
        }
        if(state == 0){
            for(int dir{0}; dir < 8; ++dir){
                int nx{x + xx1[dir]};
                int ny{y + yy1[dir]};
                if(nx < 0 || nx > n - 1 || ny < 0 || ny > n - 1) continue;
                if(dist[nx][ny][cur][state] == -1){
                    dist[nx][ny][cur][state] = A + 1;
                    Q.push({nx, ny, cur, state});
                }
            }
        }
        else if(state == 1){
            for(int dir{0}; dir < 4; ++dir){
                int nx{x + xx2[dir]};
                int ny{y + yy2[dir]};
                while(1){
                    if(nx < 0 || nx > n - 1 || ny < 0 || ny > n - 1) break;
                    if(dist[nx][ny][cur][state] == -1){
                        dist[nx][ny][cur][state] = A + 1;
                        Q.push({nx, ny, cur, state});
                    }   
                    nx += xx2[dir];
                    ny += yy2[dir];
                }
            }
        }
        else{
            for(int dir{0}; dir < 4; ++dir){
                int nx{x + xx3[dir]};
                int ny{y + yy3[dir]};
                while(1){
                    if(nx < 0 || nx > n - 1 || ny < 0 || ny > n - 1) break;
                    if(dist[nx][ny][cur][state] == -1){
                        dist[nx][ny][cur][state] = A + 1;
                        Q.push({nx, ny, cur, state});
                    }   
                    nx += xx3[dir];
                    ny += yy3[dir];
                }
            }
        }
        for(int i{0}; i < 3; ++i){
            if(dist[x][y][cur][i] == -1){
                dist[x][y][cur][i] = A + 1;
                Q.push({x, y, cur, i});
            }
        }
    }
}

int main(){
	fastio;
	int t;
	t = 1;
	while(t--){
		solve();
	}
}
