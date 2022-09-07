// 2022-09-07
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
    int x, y, dis;
    bool operator< (const st a) const{
        return dis > a.dis;
    }
};

int n;

int main() {
	fastio;
    for(int T{0};; ++T){
        cin >> n;
        if(n == 0) break;
        cout << "Problem " << T + 1 << ": ";
        vector<vi> board(n, vi(n));
        for(int i{0}; i < n; ++i){
            for(int j{0}; j < n; ++j){
                cin >> board[i][j];
            }
        }
        vector<vi> dijk(n, vi(n, (int)1e9));
        dijk[0][0] = board[0][0];
        priority_queue<st> pQ;
        pQ.push({0, 0, dijk[0][0]});
        int xx[]{-1,0,1,0};
        int yy[]{0,1,0,-1};
        while(!pQ.empty()){
            int x{pQ.top().x};
            int y{pQ.top().y};
            int dis{pQ.top().dis};
            pQ.pop();
            if(dijk[x][y] < dis) continue;
            for(int dir{0}; dir < 4; ++dir){
                int nx{x + xx[dir]};
                int ny{y + yy[dir]};
                if(nx < 0 || nx > n - 1 || ny < 0 || ny > n - 1) continue;
                if(dijk[nx][ny] > dis + board[nx][ny]){
                    dijk[nx][ny] = dis + board[nx][ny];
                    pQ.push({nx, ny, dijk[nx][ny]});
                }
            }
        }
        cout << dijk[n - 1][n - 1] << "\n";
    }
}
	

