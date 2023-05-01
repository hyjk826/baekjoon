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
    bool operator< (const st& a) const{
        return w > a.w;
    }
};

int dijk[50][50][16];
int xx1[]{-2,-2,-1,-1,1,1,2,2};
int yy1[]{-1,1,-2,2,-2,2,-1,1};
int xx2[]{-1,-1,1,1};
int yy2[]{-1,1,-1,1};
int xx3[]{-1,0,1,0};
int yy3[]{0,1,0,-1};

int main(){
	fastio;
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    int x, y;
    cin >> x >> y;
    vector<vi> board(n, vi(n, -1));
    int m;
    cin >> m;
    int cnt{0};
    for(int i{0}; i < m; ++i){
        int xx, yy;
        cin >> xx >> yy;
        board[xx][yy] = cnt++;
    }
    priority_queue<st> pQ;
    pQ.push({x, y, 0, 0});
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < n; ++j){
            for(int k{0}; k < (1 << m); ++k){
                dijk[i][j][k] = MAX;
            }
        }
    }
    while(!pQ.empty()){
        int x{pQ.top().x};
        int y{pQ.top().y};
        int state{pQ.top().state};
        int w{pQ.top().w};
        pQ.pop();
        if(dijk[x][y][state] < w) continue;
        int nstate;
        for(int dir{0}; dir < 8; ++dir){
            int nx{x + xx1[dir]};
            int ny{y + yy1[dir]};            
            nstate = state;
            if(nx < 0 || nx > n - 1 || ny < 0 || ny > n - 1) continue;
            if(board[nx][ny] != -1) nstate |= (1 << board[nx][ny]);
            if(dijk[nx][ny][nstate] > w + a){
                dijk[nx][ny][nstate] = w + a;
                pQ.push({nx, ny, nstate, w + a});
            }
        }
        for(int dir{0}; dir < 4; ++dir){
            int tx = x;
            int ty = y;
            while(1){
                tx += xx2[dir];
                ty += yy2[dir];
                nstate = state;
                if(tx < 0 || tx > n - 1 || ty < 0 || ty > n - 1) break;
                if(board[tx][ty] != -1) nstate |= (1 << board[tx][ty]);
                if(dijk[tx][ty][nstate] > w + b){
                    dijk[tx][ty][nstate] = w + b;
                    pQ.push({tx, ty, nstate, w + b});
                }   
            }
        }
        for(int dir{0}; dir < 4; ++dir){
            int tx = x;
            int ty = y;
            while(1){
                tx += xx3[dir];
                ty += yy3[dir];
                nstate = state;
                if(tx < 0 || tx > n - 1 || ty < 0 || ty > n - 1) break;
                if(board[tx][ty] != -1) nstate |= (1 << board[tx][ty]);
                if(dijk[tx][ty][nstate] > w + c){
                    dijk[tx][ty][nstate] = w + c;
                    pQ.push({tx, ty, nstate, w + c});
                }   
            }
        }
    }
    int ans{MAX};
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < n; ++j){
            ans = min(ans, dijk[i][j][(1 << m) - 1]);
        }
    }
    cout << ans;
}
