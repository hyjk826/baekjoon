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

int xx[]{-1,-1,0,1,0};
int yy[]{-1,0,1,0,-1};

int ch[1000][1000][6];

struct st{
    int x, y, dir;
};

void solve(){
	int n, m;
    cin >> n >> m;
    vector<vc> board(n, vc(m));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            cin >> board[i][j];
            for(int k{0}; k < 6; ++k){
                ch[i][j][k] = MAX;
            }
        }
    }
    ch[0][0][0] = 0;
    deque<st> Q;
    Q.push_back({0, 0, 0});
    while(!Q.empty()){
        int x{Q.front().x};
        int y{Q.front().y};
        int dir{Q.front().dir};
        Q.pop_front();
        if(dir == 0){
            for(int d{1}; d <= 4; ++d){
                if(ch[x][y][d] > ch[x][y][dir]){
                    ch[x][y][d] = ch[x][y][dir];
                    Q.push_front({x, y, d});
                }
            }
        }
        else if(dir <= 4){
            int nx{x + xx[dir]};
            int ny{y + yy[dir]};
            if(nx >= 0 && nx <= n - 1 && ny >= 0 && ny <= m - 1){
                if(ch[nx][ny][dir] > ch[x][y][dir] + 1){
                    ch[nx][ny][dir] = ch[x][y][dir] + 1;
                    Q.push_back({nx, ny, dir});
                }
            }
        }
        for(int d{1}; d <= 4; ++d){
            int nx{x + xx[d]};
            int ny{y + yy[d]};
            int nd;
            if(dir == 0) nd = 0;
            else nd = 5;
            if(nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1) continue;
            if(board[nx][ny] == '0' && ch[nx][ny][nd] > ch[x][y][dir] + 1){
                ch[nx][ny][nd] = ch[x][y][dir] + 1;
                Q.push_back({nx, ny, nd});
            }
        }
    }
    int ans{MAX};
    for(int i{0}; i < 6; ++i){
        ans = min(ans, ch[n - 1][m - 1][i]);
    }
    if(ans == MAX) ans = -1;
    cout << ans << "\n";
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
