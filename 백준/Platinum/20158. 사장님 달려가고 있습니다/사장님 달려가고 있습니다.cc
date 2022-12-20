// 2022-12-20
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
    int x, y, v, d;
};

int dp[100][100][16][4];

int main(){
	fastio;
	int n;
    cin >> n;
    vector<vi> board(n, vi(n));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < n; ++j){
            cin >> board[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    queue<st> Q;
    int xx[]{-1,0,1,0};
    int yy[]{0,1,0,-1};
    if(board[0][1] != 1){
        dp[0][1][1][1] = 1;
        Q.push({0,1,1,1});
    }
    if(board[1][0] != 1){
        dp[1][0][1][2] = 1;
        Q.push({1, 0, 1, 2});
    }
    while(!Q.empty()){
        int x{Q.front().x};
        int y{Q.front().y};
        int v{Q.front().v};
        int d{Q.front().d};
        Q.pop();
        if(x == n - 1 && y == n - 1){
            cout << dp[x][y][v][d];
            return 0;
        }
        for(int dir{0}; dir < 4; ++dir){
            if(dir == d){
                int k = v + 1;
                int nx{x + xx[dir] * k};
                int ny{y + yy[dir] * k};             
                if(nx < 0 || nx > n - 1 || ny < 0 || ny > n - 1 || dp[nx][ny][k][d] != -1) continue;
                if(board[nx][ny] && board[nx][ny] <= dp[x][y][v][d] + 1) continue;
                int a = x;
                int b = y;
                bool ok = true;
                while(!(a == nx && b == ny)){
                    if(board[a][b] != 0 && board[a][b] <= dp[x][y][v][d]){
                        ok = false;
                        break;
                    }
                    a += xx[dir];
                    b += yy[dir];                    
                }
                if(!ok) continue;
                dp[nx][ny][k][dir] = dp[x][y][v][d] + 1;
                Q.push({nx, ny, k, dir});
            }
            else{
                int nx{x + xx[dir]};
                int ny{y + yy[dir]};
                if(nx < 0 || nx > n - 1 || ny < 0 || ny > n - 1 || dp[nx][ny][1][dir] != -1) continue;
                if(board[nx][ny] && board[nx][ny] <= dp[x][y][v][d] + 1) continue;
                dp[nx][ny][1][dir] = dp[x][y][v][d] + 1;
                Q.push({nx, ny, 1, dir});
            }
        }
    }
    cout << "Fired";
}
	
