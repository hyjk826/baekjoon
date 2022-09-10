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

int xx[]{-1,0,1,0};
int yy[]{0,1,0,-1};


int main(){
    fastio;
    int t;
    cin >> t;
    while(t--){
        int n, m, k;
        cin >> m >> n >> k;
        vector<vi> board(n, vi(m));
        while(k--){
            int x, y;
            cin >> y >> x;
            board[x][y] = 1;
        }
        int ans{0};
        for(int i{0}; i < n; ++i){
            for(int j{0}; j < m; ++j){
                if(board[i][j]){
                    ans++;
                    board[i][j] = 0;
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
                            if(board[nx][ny]){
                                board[nx][ny] = 0;
                                Q.push({nx, ny});
                            }
                        }
                    }
                }
            }
        }
        cout << ans << "\n";        
    }
}