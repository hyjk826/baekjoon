// 2022-08-31
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
    cin >> m >> n;
    vector<vc> board(n, vc(m));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            cin >> board[i][j];
        }
    }
    int a{0}, b{0};
    int xx[]{-1,0,1,0};
    int yy[]{0,1,0,-1};
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            if(board[i][j] != 'F'){
                queue<pi> Q;
                Q.push({i, j});
                char c = board[i][j];
                board[i][j] = 'F';           
                int cnt{0};     
                while(!Q.empty()){
                    int x{Q.front().first};
                    int y{Q.front().second};
                    Q.pop();
                    cnt++;
                    for(int dir{0}; dir < 4; ++dir){
                        int nx{x + xx[dir]};
                        int ny{y + yy[dir]};
                        if(nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1) continue;
                        if(board[nx][ny] == c){
                            board[nx][ny] = 'F';
                            Q.push({nx, ny});
                        }
                    }
                }
                if(c == 'W') a += cnt * cnt;
                else b += cnt * cnt;
            }
        }
    }
    cout << a << " " << b;
}

