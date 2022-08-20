// 2022-08-21
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define vs vector<string>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

struct st{
    int x, y, d, cnt;
    bool operator< (const st a) const{
        return cnt > a.cnt;
    }
};

int main(){
    fastio;
	int n, m;
    cin >> n >> m;
    vector<vi> board(n, vi(m));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            cin >> board[i][j];
        }
    }
    int ch[100][100][4];
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            for(int k{0}; k < 4; ++k){
                ch[i][j][k] = -1;
            }
        }
    }
    priority_queue<st> pQ;
    int x1, y1, d1, x2, y2, d2;
    cin >> x1 >> y1 >> d1 >> x2 >> y2 >> d2;
    x1--; y1--; d1--; x2--; y2--; d2--;
    pQ.push({x1, y1, d1, 0});
    ch[x1][y1][d1] = 0;
    int xx[]{0,0,1,-1};
    int yy[]{1,-1,0,0};
    while(!pQ.empty()){
        int x{pQ.top().x};
        int y{pQ.top().y};
        int d{pQ.top().d};        
        int cnt{pQ.top().cnt};
        if(x == x2 && y == y2 && d == d2){
            cout << cnt;
            return 0;
        }
        pQ.pop();
        if(d == 0 || d == 1){
            if(ch[x][y][2] == -1){
                ch[x][y][2] = cnt + 1;
                pQ.push({x, y, 2, ch[x][y][2]});
            }
            if(ch[x][y][3] == -1){
                ch[x][y][3] = cnt + 1;
                pQ.push({x, y, 3, ch[x][y][3]});
            }
        }
        else{
            if(ch[x][y][0] == -1){
                ch[x][y][0] = cnt + 1;
                pQ.push({x, y, 0, ch[x][y][0]});
            }
            if(ch[x][y][1] == -1){
                ch[x][y][1] = cnt + 1;
                pQ.push({x, y, 1, ch[x][y][1]});
            }
        }
        int nx = x;
        int ny = y;
        for(int i{1}; i <= 3; ++i){
            nx += xx[d];
            ny += yy[d];
            if(nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1 || board[nx][ny] == 1) break;
            if(ch[nx][ny][d] == -1){
                ch[nx][ny][d] = cnt + 1;
                pQ.push({nx, ny, d, ch[nx][ny][d]});
            }
        }
    }
}