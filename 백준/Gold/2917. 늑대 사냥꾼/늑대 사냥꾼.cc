// 2022-11-26
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


int main() {
	int n, m;
    cin >> n >> m;
    vector<vc> board(n, vc(m));
    vector<vi> A(n, vi(m, MAX));
    priority_queue<st> pQ;
    vector<vi> B(n, vi(m));
    int sx, sy, tx, ty;
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            cin >> board[i][j];
            if(board[i][j] == '+'){
                pQ.push({i, j, 0});
                A[i][j] = 0;
            }
            else if(board[i][j] == 'V'){
                sx = i;
                sy = j;
            }
            else if(board[i][j] == 'J'){
                tx = i;
                ty = j;
            }
        }
    }
    int xx[]{-1,0,1,0};
    int yy[]{0,1,0,-1};
    while(!pQ.empty()){
        int x{pQ.top().x};
        int y{pQ.top().y};
        int w{pQ.top().w};
        pQ.pop();
        if(A[x][y] < w) continue;
        for(int dir{0}; dir < 4; ++dir){
            int nx{x + xx[dir]};
            int ny{y + yy[dir]};
            if(nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1) continue;
            if(A[nx][ny] > w + 1){
                A[nx][ny] = w + 1;
                pQ.push({nx, ny, w + 1});
            }
        }
    }
    pQ.push({sx, sy, A[sx][sy]});
    B[sx][sy] = A[sx][sy];
    while(!pQ.empty()){
        int x{pQ.top().x};
        int y{pQ.top().y};
        int w{pQ.top().w};
        pQ.pop();
        if(B[x][y] < w) continue;
        for(int dir{0}; dir < 4; ++dir){
            int nx{x + xx[dir]};
            int ny{y + yy[dir]};
            if(nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1) continue;
            int k = min(w, A[nx][ny]);
            if(B[nx][ny] < k){
                B[nx][ny] = k;
                pQ.push({nx, ny, k});
            }
        }
    }
    cout << B[tx][ty];
}
	
