// 2022-11-20
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
    int x, y;
    ll w;
    bool operator< (const st& a) const{
        return w > a.w;
    }
};

int main() {
	fastio;	
	int n, m;
    cin >> n >> m;
    vector<vl> board(n, vl(m));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            cin >> board[i][j];
            if(board[i][j] == -1) board[i][j] = (ll)1e18;
            if(board[i][j] == -2) board[i][j] = 0;
        }
    }
    priority_queue<st> pQ;
    vector<vl> dijk(n, vl(m, (ll)1e18));
    for(int j{1}; j < m; ++j){
        pQ.push({0, j, board[0][j]});
        dijk[0][j] = board[0][j];
    }
    for(int i{1}; i < n - 1; ++i){
        pQ.push({i, m - 1, board[i][m - 1]});
        dijk[i][m - 1] = board[i][m - 1];
    }
    int xx[]{-1,-1,-1,0,0,1,1,1};
    int yy[]{-1,0,1,-1,1,-1,0,1};
    while(!pQ.empty()){
        int x{pQ.top().x};
        int y{pQ.top().y};
        ll w{pQ.top().w};
        pQ.pop();
        if(dijk[x][y] < w) continue;
        for(int dir{0}; dir < 8; ++dir){
            int nx{x + xx[dir]};
            int ny{y + yy[dir]};
            if(nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1) continue;
            if(dijk[nx][ny] > w + board[nx][ny]){
                dijk[nx][ny] = w + board[nx][ny];
                pQ.push({nx, ny, dijk[nx][ny]});
            }
        }
    }
    ll ans{(ll)1e18};
    for(int i{0}; i < n; ++i){
        ans = min(ans, dijk[i][0]);
    }
    for(int j{0}; j < m; ++j){
        ans = min(ans, dijk[n - 1][j]);
    }
    if(ans == (ll)1e18) cout << -1;
    else cout << ans;
}
	

