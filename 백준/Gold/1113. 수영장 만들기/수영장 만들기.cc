// 2022-12-07
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
	int n, m;
    cin >> n >> m;
    vector<vi> board(n + 2, vi(m + 2));
    for(int i{1}; i <= n; ++i){
        for(int j{1}; j <= m; ++j){
            char c;
            cin >> c;
            board[i][j] = c - '0';
        }
    }
    vector<vi> dijk(n + 2, vi(m + 2, MAX));
    dijk[0][0] = 0;
    priority_queue<st> pQ;
    pQ.push({0, 0, 0});
    int xx[]{-1,0,1,0};
    int yy[]{0,1,0,-1};
    while(!pQ.empty()){
        int x{pQ.top().x};
        int y{pQ.top().y};
        int w{pQ.top().w};
        pQ.pop();
        if(dijk[x][y] < w) continue;
        for(int dir{0}; dir < 4; ++dir){
            int nx{x + xx[dir]};
            int ny{y + yy[dir]};
            if(nx < 0 || nx > n + 1 || ny < 0 || ny > m + 1) continue;
            int nw = max(w, board[nx][ny]);
            if(dijk[nx][ny] > nw){
                dijk[nx][ny] = nw;
                pQ.push({nx, ny, nw});
            }
        }
    }
    int ans{0};
    for(int i{1}; i <= n; ++i){
        for(int j{1}; j <= m; ++j){
            ans += dijk[i][j] - board[i][j];
        }
    }
    cout << ans;
}
	
