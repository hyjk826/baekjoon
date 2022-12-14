// 2022-12-14
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

int main() {
	fastio;
    int n;
    cin >> n;
    vector<vi> board(n, vi(n));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < n; ++j){
            cin >> board[i][j];
        }
    }
    int xx[]{1,0};
    int yy[]{0,1};
    queue<pi> Q;
    vector<vi> ch(n, vi(n));
    Q.push({0, 0});
    ch[0][0] = 1;
    while(!Q.empty()){
        int x{Q.front().first};
        int y{Q.front().second};
        Q.pop();
        for(int dir{0}; dir < 2; ++dir){
            int nx{x + xx[dir] * board[x][y]};
            int ny{y + yy[dir] * board[x][y]};
            if(nx < 0 || nx > n - 1 || ny < 0 || ny > n - 1) continue;
            if(ch[nx][ny] == 0){
                ch[nx][ny] = 1;
                Q.push({nx, ny});
            }
        }
    }
    if(ch[n - 1][n - 1]) cout << "HaruHaru";
    else cout << "Hing";
}
	
