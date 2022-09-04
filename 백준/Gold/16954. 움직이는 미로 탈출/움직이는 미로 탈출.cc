// 2022-09-05
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
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

struct s{
    int x, y, t;
};

int main() {
	fastio;
    vector<vc> board(8, vc(8));
    for(int i{0}; i < 8; ++i){
        for(int j{0}; j < 8; ++j){
            cin >> board[i][j];
        }
    }
    int ch[8][8][50]{};
    queue<s> Q;
    Q.push({7, 0, 0});
    ch[7][0][0] = 1;
    int xx[]{-1,-1,-1,0, 0, 0,1,1,1};
    int yy[]{-1,0,1,-1,0,1,-1,0,1};
    while(!Q.empty()){
        int x{Q.front().x};
        int y{Q.front().y};
        int t{Q.front().t};
        if(x == 0 && y == 7){
            cout << 1;
            return 0;
        }
        Q.pop();
        for(int dir{0}; dir < 9; ++dir){
             int nx{x + xx[dir]};
             int ny{y + yy[dir]};
             if(nx < 0 || nx > 7 || ny < 0 || ny > 7) continue;
             if(ch[nx][ny][t + 1] == 1) continue;
             if(nx - t >= 0 && board[nx - t][ny] == '#') continue;
             if(nx - (t + 1) >= 0 && board[nx - (t + 1)][ny] == '#') continue;
             ch[nx][ny][t + 1] = 1;
             Q.push({nx, ny, t + 1});
        }
    }
    cout << 0;
}
	

