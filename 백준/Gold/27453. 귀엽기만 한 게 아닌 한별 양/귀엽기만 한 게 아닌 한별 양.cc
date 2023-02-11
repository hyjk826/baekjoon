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
	int x, y, px, py, a, b;
};

int ch[1000][1000][5][5];

int main(){
	fastio;
	int n, m, k;
	cin >> n >> m >> k;
	vector<vc> board(n, vc(m));
	int sx, sy, tx, ty;
	for(int i{0}; i < n; ++i){
		for(int j{0}; j < m; ++j){
			cin >> board[i][j];
			if(board[i][j] == 'S'){
				sx = i; sy = j;
			}
			else if(board[i][j] == 'H'){
				tx = i; ty = j;
			}
			for(int a{0}; a < 5; ++a){
                for(int b{0}; b < 5; ++b){
                    ch[i][j][a][b] = -1;
                }
            }
		}
	}
	queue<st> Q;
	Q.push({sx, sy, -1, -1, 4, 4});
	ch[sx][sy][4][4] = 0;
	int xx[]{-1,0,1,0};
	int yy[]{0,1,0,-1};
	while(!Q.empty()){
		int x{Q.front().x};
		int y{Q.front().y};
		int px{Q.front().px};
		int py{Q.front().py};
        int a{Q.front().a};
        int b{Q.front().b};
		Q.pop();
		for(int dir{0}; dir < 4; ++dir){
			int nx{x + xx[dir]};
			int ny{y + yy[dir]};
			if(nx == px && ny == py) continue;
			if(nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1) continue;
			if(board[nx][ny] == 'X') continue;
            if(nx == tx && ny == ty){
                cout << ch[x][y][a][b] + 1; return 0;
            }
            int sum{0};
            if(board[x][y] != 'S') sum += board[x][y] - '0';
            if(px != -1 && board[px][py] != 'S') sum += board[px][py] - '0';
            sum += board[nx][ny] - '0';
            if(sum > k) continue;
            if(ch[nx][ny][b][dir] == -1){
                ch[nx][ny][b][dir] = ch[x][y][a][b] + 1;
                Q.push({nx, ny, x, y, b, dir});   
            }
		}
	}
	cout << -1;
}
