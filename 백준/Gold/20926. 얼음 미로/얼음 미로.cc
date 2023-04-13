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
    int x, y, w;
    bool operator< (const st& a) const{
        return w > a.w;
    }
};

int dp[501][501][4]; // EWSN
int dijk[501][501];
char board[501][501];

int main(){
	fastio;
    int n, m;
    cin >> m >> n;
    int sx, sy, tx, ty;
    for(int i{1}; i <= n; ++i){
        for(int j{1}; j <= m; ++j){
            cin >> board[i][j];
            if(board[i][j] == 'T'){
                sx = i; sy = j;
            }
            if(board[i][j] == 'E'){
                tx = i; ty = j;                
            }
        }
    }
    int xx[]{0,0,1,-1};
    int yy[]{1,-1,0,0};
    memset(dp, -1, sizeof(dp));
    function<int(int,int,int)> f = [&](int x, int y, int dir){
        if(x <= 0 || x > n || y <= 0 || y > m) return (int)1e9;
        if(dp[x][y][dir] != -1) return dp[x][y][dir];
        if(board[x][y] == 'H') return dp[x][y][dir] = (int)1e9;
        if(board[x][y] == 'E') return dp[x][y][dir] = 1;
        if(board[x][y] == 'R') return dp[x][y][dir] = 0;
        return dp[x][y][dir] = f(x + xx[dir], y + yy[dir], dir) + 1;
    };
    vector<vi> A(n + 1, vi(m + 1));
    vector<vi> B(n + 1, vi(m + 1));
    for(int i{1}; i <= n; ++i){
        for(int j{1}; j <= m; ++j){
            dijk[i][j] = MAX;
            A[i][j] += A[i][j - 1];
            if('0' <= board[i][j] && board[i][j] <= '9') A[i][j] += board[i][j] - '0';
        }
    }
    for(int j{1}; j <= m; ++j){
        for(int i{1}; i <= n; ++i){
            B[i][j] += B[i - 1][j];
            if('0' <= board[i][j] && board[i][j] <= '9') B[i][j] += board[i][j] - '0';
        }
    }
    priority_queue<st> pQ;
    pQ.push({sx, sy, 0});
    dijk[sx][sy] = 0;
    while(!pQ.empty()){
        int x{pQ.top().x};
        int y{pQ.top().y};
        int w{pQ.top().w};
        pQ.pop();
        if(x == tx && y == ty){
            cout << w; return 0;
        }
        if(dijk[x][y] < w) continue;
        for(int dir{0}; dir < 4; ++dir){
            int a = f(x, y, dir) - 1;
            if(a == 0) continue;
            if(dir == 0){
                if(y + a <= m && dijk[x][y + a] > w + A[x][y + a] - A[x][y]){
                    dijk[x][y + a] = w + A[x][y + a] - A[x][y];
                    pQ.push({x, y + a, dijk[x][y + a]});
                } 
            }
            else if(dir == 1){                
                if(y - a > 0 && dijk[x][y - a] > w + A[x][y - 1] - A[x][y - a - 1]){
                    dijk[x][y - a] = w + A[x][y - 1] - A[x][y - a - 1];
                    pQ.push({x, y - a, dijk[x][y - a]});
                }
            }
            else if(dir == 2){
                if(x + a <= n && dijk[x + a][y] > w + B[x + a][y] - B[x][y]){
                    dijk[x + a][y] = w + B[x + a][y] - B[x][y];
                    pQ.push({x + a, y, dijk[x + a][y]});
                }
            }
            else{
                if(x - a > 0 && dijk[x - a][y] > w + B[x - 1][y] - B[x - a - 1][y]){
                    dijk[x - a][y] = w + B[x - 1][y] - B[x - a - 1][y];
                    pQ.push({x - a, y, dijk[x - a][y]});
                }
            }
        }
    }
    cout << -1;
}
