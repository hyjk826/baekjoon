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

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<vc> board(n, vc(m));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            cin >> board[i][j];
        }
    }
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    sx--; sy--; tx--; ty--;
    queue<pi> Q;
    vector<vi> ch(n, vi(m, MAX));
    Q.push({sx, sy});
    ch[sx][sy] = 0;
    int xx[]{-1,0,1,0};
    int yy[]{0,1,0,-1};
    while(!Q.empty()){
        int x{Q.front().first};
        int y{Q.front().second};
        Q.pop();
        if(x == tx && y == ty){
            cout << ch[x][y]; return;
        }
        for(int dir{0}; dir < 4; ++dir){
            for(int i{1}; i <= k; ++i){
                int nx{x + xx[dir] * i};
                int ny{y + yy[dir] * i};
                if(nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1 || board[nx][ny] == '#') break;
                if(ch[nx][ny] < ch[x][y] + 1) break;
                if(ch[nx][ny] == MAX){
                    ch[nx][ny] = ch[x][y] + 1;
                    Q.push({nx, ny});
                }
            }
        }
    }
    cout << -1;
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
