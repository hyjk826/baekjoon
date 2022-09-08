// 2022-09-08
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

struct st{
    int x, y, t;
};

int ch[1000][1000][2]{};

int main() {
	fastio;
    int n, m;
    cin >> n >> m;
    vector<vc> board(n, vc(m));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            cin >> board[i][j];
            for(int k{0}; k < 2; ++k){
                ch[i][j][k] = -1;
            }
        }
    }
    queue<st> Q;
    Q.push({0, 0, 1});
    ch[0][0][1] = 1;
    int xx[]{-1,0,1,0};
    int yy[]{0,1,0,-1};
    while(!Q.empty()){
        int x{Q.front().x};
        int y{Q.front().y};
        int t{Q.front().t};
        if(x == n - 1 && y == m - 1){
            cout << ch[x][y][t];
            return 0;
        }
        Q.pop();
        for(int dir{0}; dir < 4; ++dir){
            int nx{x + xx[dir]};
            int ny{y + yy[dir]};
            if(nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1) continue;
            if(board[nx][ny] == '0'){
                if(ch[nx][ny][t] == -1){
                    ch[nx][ny][t] = ch[x][y][t] + 1;
                    Q.push({nx, ny, t});
                }
            }
            else{
                if(t == 0) continue;
                if(ch[nx][ny][0] == -1){
                    ch[nx][ny][0] = ch[x][y][t] + 1;
                    Q.push({nx, ny, 0});
                }
            }
        }
    }
    cout << -1;
}
	

