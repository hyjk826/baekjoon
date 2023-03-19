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

int main(){
	fastio;
    int n, m, sx, sy, tx, ty;
    cin >> n >> m >> sx >> sy >> tx >> ty;
    sx--; sy--; tx--; ty--;
    vector<vc> board(n, vc(m));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            cin >> board[i][j];
            if(board[i][j] == '*') board[i][j] = '0';
            if(board[i][j] == '#') board[i][j] = '0';
        }
    }
    vector<vi> ch(n, vi(m, -1));
    deque<pi> dQ;
    dQ.push_back({sx, sy});
    ch[sx][sy] = 1;
    int xx[]{-1,0,1,0};
    int yy[]{0,1,0,-1};
    while(!dQ.empty()){
        int x{dQ.front().first};
        int y{dQ.front().second};
        dQ.pop_front();
        if(x == tx && y == ty){
            cout << ch[x][y]; return 0;
        }
        for(int dir{0}; dir < 4; ++dir){
            int nx{x + xx[dir]};
            int ny{y + yy[dir]};
            if(nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1) continue;
            if(board[nx][ny] == '0'){
                if(ch[nx][ny] == -1){
                    ch[nx][ny] = ch[x][y];
                    dQ.push_front({nx, ny});
                }
            }
            else{
                if(ch[nx][ny] == -1){
                    ch[nx][ny] = ch[x][y] + 1;
                    dQ.push_back({nx, ny});
                }
            }
        }
    }
    
}
