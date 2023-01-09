// 2023-01-09
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
};

int main(){
	fastio;
    int n, m, k;
    cin >> n >> m >> k;
    vector<st> vec(k);
    vector<vi> board(n, vi(m));
    vector<vp> g(3001);
    for(int i{0}; i < k; ++i){
        cin >> vec[i].x >> vec[i].y >> vec[i].cnt;
        vec[i].x--; vec[i].y--;
        g[vec[i].cnt].push_back({vec[i].x, vec[i].y});
    }
    int xx[]{-1,0,1,0};
    int yy[]{0,1,0,-1};
    queue<pi> Q;
    for(int i{3000}; i >= 1; --i){
        for(auto& j : g[i]){
            Q.push({j.first, j.second});
            if(board[j.first][j.second] == 0){
                board[j.first][j.second] = 1;
                Q.push({j.first, j.second});
            }
        }
        while(!Q.empty()){
            int x{Q.front().first};
            int y{Q.front().second};
            Q.pop();
            for(int dir{0}; dir < 4; ++dir){
                int nx{x + xx[dir]};
                int ny{y + yy[dir]};
                if(nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1) continue;
                if(board[nx][ny] == 0){
                    board[nx][ny] = 1;
                    g[i - 1].push_back({nx, ny});
                }
            }
        }
    }
    int ans{0};
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            if(board[i][j]) ans++;
        }
    }
    cout << ans;
}
