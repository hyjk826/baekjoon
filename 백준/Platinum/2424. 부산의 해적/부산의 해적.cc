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


int BB[700][700][4];

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vi> board(n, vi(m));
    int ax, ay, bx, by;
    int tx, ty;
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            char c;
            cin >> c;
            if(c == 'I') board[i][j] = -1;
            else if(c == 'Y') {
                ax = i; ay = j;
            }
            else if(c == 'V'){
                bx = i, by = j;
            }
            else if(c == 'T'){
                tx = i; ty = j;
            }
        }
    }
    vector<vi> B(n, vi(m, MAX));
    queue<pi> Q;
    Q.push({bx, by});
    B[bx][by] = 0;
    int xx[]{-1,0,1,0};
    int yy[]{0,1,0,-1};
    while(!Q.empty()){
        int x{Q.front().first};
        int y{Q.front().second};
        Q.pop();
        for(int dir{0}; dir < 4; ++dir){
            int nx{x + xx[dir]};
            int ny{y + yy[dir]};
            if(nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1) continue;
            if(board[nx][ny] == -1) continue;
            if(B[nx][ny] == MAX){
                B[nx][ny] = B[x][y] + 1;
                Q.push({nx, ny});
            }
        }
    }
    memset(BB, -1, sizeof(BB));
    function<int(int,int,int)> f = [&](int x, int y, int dir){
        if(x < 0 || x > n - 1 || y < 0 || y > m - 1) return MAX;
        if(BB[x][y][dir] != -1) return BB[x][y][dir];
        if(board[x][y] == -1) return BB[x][y][dir] = MAX;
        int& ret = BB[x][y][dir];
        ret = B[x][y];
        return ret = min(ret, f(x + xx[dir], y + yy[dir], dir));
    };
    vector<vi> BBB(n, vi(m, MAX));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            for(int dir{0}; dir < 4; ++dir){
                BBB[i][j] = min(BBB[i][j], f(i, j, dir));
            }
        }
    }
    vector<vi> A(n, vi(m, MAX));
    Q.push({ax, ay});
    A[ax][ay] = 0;
    while(!Q.empty()){
        int x{Q.front().first};
        int y{Q.front().second};
        Q.pop();
        for(int dir{0}; dir < 4; ++dir){
            int nx{x + xx[dir]};
            int ny{y + yy[dir]};
            if(nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1) continue;
            if(board[nx][ny] == -1) continue;
            if(A[x][y] + 1 >= BBB[nx][ny]) continue;
            if(A[nx][ny] > A[x][y] + 1){
                A[nx][ny] = A[x][y] + 1;
                Q.push({nx, ny});
            }
        }
    }
    if(A[tx][ty] == MAX) cout << "NO";
    else cout << "YES";
}


int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
