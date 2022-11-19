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
    int x, y, flag;
    ll w;
    bool operator< (const st& a) const{
        return w > a.w;
    }
};

ll dijk[100][100][3];


int main() {
	fastio;
    int n, t;
    cin >> n >> t;
    vector<vi> board(n, vi(n));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < n; ++j){
            cin >> board[i][j];
            for(int k{0}; k < 3; ++k) dijk[i][j][k] = LLONG_MAX;
        }
    }
    dijk[0][0][0] = 0;
    priority_queue<st> pQ;
    pQ.push({0, 0, 0, 0});
    int xx[]{-1,0,1,0};
    int yy[]{0,1,0,-1};
    while(!pQ.empty()){
        int x{pQ.top().x};
        int y{pQ.top().y};
        int flag{pQ.top().flag};
        ll w{pQ.top().w};
        pQ.pop();
        if(dijk[x][y][flag] < w) continue;
        for(int dir{0}; dir < 4; ++dir){
            int nx{x + xx[dir]};
            int ny{y + yy[dir]};
            if(nx < 0 || nx > n - 1 || ny < 0 || ny > n - 1) continue;
            ll nw{w + t};
            int nflag = (flag + 1) % 3;
            if(nflag == 0){
                nw += board[nx][ny];
            }
            if(dijk[nx][ny][nflag] > nw){
                dijk[nx][ny][nflag] = nw;
                pQ.push({nx, ny, nflag, nw});
            }
        }
    }
    ll ans{LLONG_MAX};
    for(int i{0}; i < 3; ++i){
        ans = min(ans, dijk[n - 1][n - 1][i]);
    }
    cout << ans;
}
	

