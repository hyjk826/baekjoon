// 2022-09-06
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

struct st{
    int x, y, d;
    bool operator< (const st a){
        return d > a.d;
    }
};

int main() {
	fastio;
    int n, m;
    cin >> n >> m;
    vector<vi> board(n, vi(m));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            cin >> board[i][j];
        }
    }
    vector<vi> ans(n, vi(m, (int)1e9));
    deque<st> Q;    
    Q.push_back({0, 0, 0});
    ans[0][0] = board[0][0];
    int xx[]{-1,0,1,0};
    int yy[]{0,1,0,-1};
    while(!Q.empty()){
        int x{Q.front().x};
        int y{Q.front().y};
        int d{Q.front().d};
        Q.pop_front();
        if(ans[x][y] < d) continue;
        for(int dir{0}; dir < 4; ++dir){
            int nx{x + xx[dir]};
            int ny{y + yy[dir]};
            if(nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1 || board[nx][ny] == -1) continue;
            if(ans[nx][ny] > ans[x][y] + board[nx][ny]){                
                ans[nx][ny] = ans[x][y] + board[nx][ny];
                if(board[nx][ny] == 0){
                    Q.push_front({nx, ny, ans[nx][ny]});
                }
                else Q.push_back({nx, ny, ans[nx][ny]});
            }
        }
    }
    if(ans[n - 1][m - 1] == (int)1e9) cout << -1;
    else cout << ans[n - 1][m - 1];
}
	

