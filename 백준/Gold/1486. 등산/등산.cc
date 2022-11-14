// 2022-11-14
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
	fastio;
    int n, m, t, d;
    cin >> n >> m >> t >> d;
    vector<vi> board(n, vi(m));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            char c;
            cin >> c;
            if('A' <= c && c <= 'Z') board[i][j] = c - 'A';
            else board[i][j] = c - 'a' + 26;
        }
    }
    int xx[]{-1,0,1,0};
    int yy[]{0,1,0,-1};
    vector<vi> dijk(n, vi(m, MAX));
    priority_queue<st> pQ;
    pQ.push({0, 0, 0});
    dijk[0][0] = 0;
    while(!pQ.empty()){
        int x{pQ.top().x};
        int y{pQ.top().y};
        int w{pQ.top().w};
        pQ.pop();
        if(dijk[x][y] < w) continue;
        for(int dir{0}; dir < 4; ++dir){
            int nx{x + xx[dir]};
            int ny{y + yy[dir]};
            if(nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1) continue;
            if(abs(board[nx][ny] - board[x][y]) > t) continue;
            if(board[nx][ny] <= board[x][y]){
                if(dijk[nx][ny] > w + 1){
                    dijk[nx][ny] = w + 1;
                    pQ.push({nx, ny, w + 1});
                }
            }
            else{
                int k = board[nx][ny] - board[x][y];
                k *= k;
                if(dijk[nx][ny] > w + k){
                    dijk[nx][ny] = w + k;
                    pQ.push({nx, ny, w + k});
                }
            }
        }
    }
    vector<vi> dijk2(n, vi(m, MAX));
    pQ.push({0, 0, 0});
    dijk2[0][0] = 0;
    while(!pQ.empty()){
        int x{pQ.top().x};
        int y{pQ.top().y};
        int w{pQ.top().w};
        pQ.pop();
        if(dijk2[x][y] < w) continue;
        for(int dir{0}; dir < 4; ++dir){
            int nx{x + xx[dir]};
            int ny{y + yy[dir]};
            if(nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1) continue;
            if(abs(board[nx][ny] - board[x][y]) > t) continue;
            if(board[nx][ny] >= board[x][y]){
                if(dijk2[nx][ny] > w + 1){
                    dijk2[nx][ny] = w + 1;
                    pQ.push({nx, ny, w + 1});
                }
            }
            else{
                int k = board[nx][ny] - board[x][y];
                k *= k;
                if(dijk2[nx][ny] > w + k){
                    dijk2[nx][ny] = w + k;
                    pQ.push({nx, ny, w + k});
                }
            }
        }
    }
    int ans{0};
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            if(dijk[i][j] == MAX || dijk2[i][j] == MAX) continue;
            if(dijk[i][j] + dijk2[i][j] <= d){
                ans = max(ans, board[i][j]);
            }
        }
    }
    cout << ans;
}
	

