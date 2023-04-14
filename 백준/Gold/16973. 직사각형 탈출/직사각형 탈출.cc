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
    vector<vi> board(n + 1, vi(m + 1));
    for(int i{1}; i <= n; ++i){
        for(int j{1}; j <= m; ++j){
            cin >> board[i][j];
        }
    }
    vector<vi> A = board;
    vector<vi> B = board;
    for(int i{1}; i <= n; ++i){
        for(int j{2}; j <= m; ++j){
            A[i][j] += A[i][j - 1];
        }
    }
    for(int j{1}; j <= m; ++j){
        for(int i{2}; i <= n; ++i){
            B[i][j] += B[i - 1][j];
        }
    }
    int h, w, sx, sy, tx, ty;
    cin >> h >> w >> sx >> sy >> tx >> ty;
    queue<pi> Q;
    vector<vi> ch(n + 1, vi(m + 1, -1));
    ch[sx][sy] = 0;
    Q.push({sx, sy});
    int xx[]{-1,0,1,0};
    int yy[]{0,1,0,-1};
    function<bool(int,int)> f = [&](int x, int y){
        return (x <= 0 || x > n || y <= 0 || y > m);
    };
    while(!Q.empty()){
        int x{Q.front().first};
        int y{Q.front().second};
        Q.pop();
        if(x == tx && y == ty){
            cout << ch[x][y]; return 0;
        }
        for(int dir{0}; dir < 4; ++dir){
            int nx{x + xx[dir]};
            int ny{y + yy[dir]};
            int k{0};
            if(dir == 0){
                if(f(x - 1, y + w - 1)) continue;
                k = A[x - 1][y + w - 1] - A[x - 1][y - 1];
            }
            else if(dir == 1){
                if(f(x + h - 1, y + w)) continue;
                k = B[x + h - 1][y + w] - B[x - 1][y + w];
            }
            else if(dir == 2){
                if(f(x + h, y + w - 1)) continue;
                k = A[x + h][y + w - 1] - A[x + h][y - 1];
            }
            else{
                if(f(x + h - 1, y - 1)) continue;
                k = B[x + h - 1][y - 1] - B[x - 1][y - 1];
            }
            if(k) continue;
            if(ch[nx][ny] == -1){
                ch[nx][ny] = ch[x][y] + 1;
                Q.push({nx, ny});
            }
        }
    }
    cout << -1;
}
