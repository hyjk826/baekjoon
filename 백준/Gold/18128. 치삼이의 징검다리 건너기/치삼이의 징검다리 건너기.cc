// 2022-12-21
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


int main(){
	fastio;
	int n, w;
    cin >> n >> w;
    vp A(w);
    for(int i{0}; i < w; ++i){
        cin >> A[i].first >> A[i].second;
        A[i].first--;
        A[i].second--;
    }
    vector<vc> board(n, vc(n));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < n; ++j){
            cin >> board[i][j];
        }
    }
    vector<vi> dijk1(n, vi(n, MAX));
    priority_queue<st> pQ;
    for(int i{0}; i < w; ++i){
        pQ.push({A[i].first, A[i].second, 0});
        dijk1[A[i].first][A[i].second] = 0;
    }
    int xx[]{-1,0,1,0};
    int yy[]{0,1,0,-1};
    while(!pQ.empty()){
        int x{pQ.top().x};
        int y{pQ.top().y};
        int w{pQ.top().w};
        pQ.pop();
        if(dijk1[x][y] < w) continue;
        for(int dir{0}; dir < 4; ++dir){
            int nx{x + xx[dir]};
            int ny{y + yy[dir]};
            if(nx < 0 || nx > n - 1 || ny < 0 || ny > n - 1) continue;
            if(dijk1[nx][ny] > w + 1){
                dijk1[nx][ny] = w + 1;
                pQ.push({nx, ny, w + 1});
            }
        }
    }
    dijk1[n - 1][n - 1] = 0;
    vector<vi> dijk2(n, vi(n, MAX));
    dijk2[0][0] = 0;
    pQ.push({0, 0, 0});
    int xx2[]{-1,-1,-1,0,0,1,1,1};
    int yy2[]{-1,0,1,-1,1,-1,0,1};
    while(!pQ.empty()){
        int x{pQ.top().x};
        int y{pQ.top().y};
        int w{pQ.top().w};
        pQ.pop();
        if(dijk2[x][y] < w) continue;
        for(int dir{0}; dir < 8; ++dir){
            int nx{x + xx2[dir]};
            int ny{y + yy2[dir]};
            if(nx < 0 || nx > n - 1 || ny < 0 || ny > n - 1 || board[nx][ny] == '0') continue;
            int nw = max(w, dijk1[nx][ny]);
            if(dijk2[nx][ny] > nw){
                dijk2[nx][ny] = nw;
                pQ.push({nx, ny, nw});
            }
        }
    }
    if(dijk2[n - 1][n - 1] == MAX) cout << -1;
    else cout << dijk2[n - 1][n - 1];
}
	
