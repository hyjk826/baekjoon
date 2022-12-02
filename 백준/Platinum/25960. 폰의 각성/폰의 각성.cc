// 2022-12-02
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
    int x, y, cnt;
    bool operator< (const st& a) const{
        return cnt > a.cnt;
    }
};


int main() {
	fastio;
	int n;
    cin >> n;
    int sx, sy, tx, ty;
    vector<vc> board(n, vc(n));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < n; ++j){
            cin >> board[i][j];
            if(board[i][j] == 'P'){
                sx = i; sy = j;
                board[i][j] = '0';
            }
            else if(board[i][j] == 'K'){
                tx = i; ty = j;
            }
        }
    }
    vector<vi> dijk(n, vi(n, MAX));
    dijk[sx][sy] = 0;
    priority_queue<st> pQ;
    pQ.push({sx, sy, 0});
    int px[]{-1,-1,-1,0,0,1,1,1};
    int py[]{-1,0,1,-1,1,-1,0,1};
    int bx[]{-1,-1,1,1};
    int by[]{-1,1,-1,1};
    int rx[]{-1,0,1,0};
    int ry[]{0,1,0,-1};
    int nnx[]{-2,-2,-1,-1,1,1,2,2};
    int nny[]{-1,1,-2,2,-2,2,-1,1};
    while(!pQ.empty()){
        int x{pQ.top().x};
        int y{pQ.top().y};
        int cnt{pQ.top().cnt};
        pQ.pop();
        if(dijk[x][y] < cnt) continue;
        if(sx == x && sy == y){
            for(int dir{0}; dir < 8; ++dir){
                int nx{x + px[dir]};
                int ny{y + py[dir]};
                if(nx < 0 || nx > n - 1 || ny < 0 || ny > n - 1 || board[nx][ny] == '0') continue;
                if(dijk[nx][ny] > cnt + 1){
                    dijk[nx][ny] = cnt + 1;
                    pQ.push({nx, ny, cnt + 1});                    
                }
            }
        }
        else if(board[x][y] == 'Q'){
            for(int dir{0}; dir < 8; ++dir){
                int nx = x;
                int ny = y;
                int a{0};
                while(1){
                    nx += px[dir];
                    ny += py[dir];
                    a++;
                    if(nx < 0 || nx > n - 1 || ny < 0 || ny > n - 1) break;
                    if(board[nx][ny] == '0') continue;
                    if(dijk[nx][ny] > cnt + a){
                        dijk[nx][ny] = cnt + a;
                        pQ.push({nx, ny, cnt + a});
                    }
                    break;
                }
            }
        }
        else if(board[x][y] == 'R'){
            for(int dir{0}; dir < 4; ++dir){
                int nx = x;
                int ny = y;
                int a{0};
                while(1){
                    nx += rx[dir];
                    ny += ry[dir];
                    a++;
                    if(nx < 0 || nx > n - 1 || ny < 0 || ny > n - 1) break;
                    if(board[nx][ny] == '0') continue;
                    if(dijk[nx][ny] > cnt + a){
                        dijk[nx][ny] = cnt + a;
                        pQ.push({nx, ny, cnt + a});
                    }
                    break;
                }
            }
        }
        else if(board[x][y] == 'B'){
            for(int dir{0}; dir < 4; ++dir){
                int nx = x;
                int ny = y;
                int a{0};
                while(1){
                    nx += bx[dir];
                    ny += by[dir];
                    a++;
                    if(nx < 0 || nx > n - 1 || ny < 0 || ny > n - 1) break;
                    if(board[nx][ny] == '0') continue;
                    if(dijk[nx][ny] > cnt + a){
                        dijk[nx][ny] = cnt + a;
                        pQ.push({nx, ny, cnt + a});                        
                    }
                    break;
                }
            }
        }
        else if(board[x][y] == 'N'){
            for(int dir{0}; dir < 8; ++dir){
                int nx = x + nnx[dir];
                int ny = y + nny[dir];
                if(nx < 0 || nx > n - 1 || ny < 0 || ny > n - 1) continue;
                if(dijk[nx][ny] > cnt + 2){
                    dijk[nx][ny] = cnt + 2;
                    pQ.push({nx, ny, cnt + 2});
                }
            }
        }
    }
    if(dijk[tx][ty] == MAX) cout << -1;
    else cout << dijk[tx][ty];
}
	
