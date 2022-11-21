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

struct st{
    int x, y, state, w;
    bool operator<(const st& a) const{
        return w > a.w;
    }
};



int main() {
	fastio;	
	int n, m;
    cin >> m >> n;
    int sx, sy, tx, ty;
    vector<vc> board(n, vc(m));
    map<pi, int> mp;
    int cnt{0};
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            cin >> board[i][j];
            if(board[i][j] == 'X'){
                board[i][j] == '.';
                mp[{i, j}] = cnt++;
            }
            else if(board[i][j] == 'S'){
                sx = i; sy = j;
            }
            else if(board[i][j] == 'E'){
                tx = i; ty = j;
            }
        }
    }
    vector<vector<vi> > dijk(n, vector<vi>(m, vi((1 << cnt), MAX)));
    priority_queue<st> pQ;
    pQ.push({sx, sy, 0, 0});
    dijk[sx][sy][0] = 0;
    int xx[]{-1,0,1,0};
    int yy[]{0,1,0,-1};
    while(!pQ.empty()){
        int x{pQ.top().x};
        int y{pQ.top().y};
        int state{pQ.top().state};
        int w{pQ.top().w};
        pQ.pop();
        if(dijk[x][y][state] < w) continue;
        for(int dir{0}; dir < 4; ++dir){
            int nx{x + xx[dir]};
            int ny{y + yy[dir]};
            if(nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1 || board[nx][ny] == '#') continue;
            int k{0};
            if(mp.count({nx, ny})){
                k = (1 << mp[{nx, ny}]);
            }
            if(dijk[nx][ny][state | k] > w + 1){
                dijk[nx][ny][state | k] = w + 1;
                pQ.push({nx, ny, state | k, w + 1});
            }
        }
    }
    cout << dijk[tx][ty][(1 << cnt) - 1];
}
	

