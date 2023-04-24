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

int main(){
	fastio;
    int n, m;
    cin >> n >> m;
    int xx[]{-1,-1,-1,0,0,1,1,1};
    int yy[]{-1,0,1,-1,1,-1,0,1};
    vector<vi> board(n, vi(m));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            cin >> board[i][j];
        }
    }
    int ans{0};
    vector<vi> ch(n, vi(m));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            if(ch[i][j]) continue;
            ch[i][j] = 1;
            queue<pi> Q;
            Q.push({i, j});
            vp A;
            while(!Q.empty()){
                int x{Q.front().first};
                int y{Q.front().second};
                Q.pop();
                A.push_back({x, y});
                for(int dir{0}; dir < 8; ++dir){
                    int nx{x + xx[dir]};
                    int ny{y + yy[dir]};
                    if(nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1) continue;
                    if(ch[nx][ny] == 0 && board[nx][ny] == board[x][y]){
                        ch[nx][ny] = 1;
                        Q.push({nx, ny});
                    }
                }
            }
            bool ok = true;
            for(auto& a : A){
                for(int dir{0}; dir < 8; ++dir){
                    int nx{a.first + xx[dir]};
                    int ny{a.second + yy[dir]};
                    if(nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1) continue;
                    ok &= (board[nx][ny] <= board[a.first][a.second]);
                }
            }
            if(ok) {
                ans++;
            }
        }
    }
    cout << ans;
}
