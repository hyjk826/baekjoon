// 2022-11-21
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
    int sum{0};
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            cin >> board[i][j];
            if(board[i][j] == '1') sum++;
        }
    }
    int xx[]{-1,0,1,0};
    int yy[]{0,1,0,-1};
    int ans{MAX};
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            for(int a{i}; a < n; ++a){
                for(int b{j + 1}; b < m; ++b){
                    if(board[i][j] == '1' || board[a][b] == '1') continue;
                    vector<vi> ch(n, vi(m, -1));
                    ch[i][j] = 0;
                    ch[a][b] = 0;
                    queue<pi> Q;
                    Q.push({i, j});
                    Q.push({a, b});
                    int c{0};
                    while(!Q.empty()){
                        int x{Q.front().first};
                        int y{Q.front().second};
                        Q.pop();
                        if(board[x][y] == '1') c = ch[x][y];
                        for(int dir{0}; dir < 4; ++dir){
                            int nx{x + xx[dir]};
                            int ny{y + yy[dir]};
                            if(nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1) continue;
                            if(ch[nx][ny] == -1){
                                ch[nx][ny] = ch[x][y] + 1;
                                Q.push({nx, ny});
                            }
                        }
                    }
                    ans = min(ans, c);
                }
            }
        }
    }
    cout << ans;
}
	

