// 2022-12-04
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

struct st {
    int a, b, d;
    bool operator< (const st& x) const {
        return d > x.d;
    }
};

int main() {
    fastio;
    int n, m;
    cin >> n >> m;
    vector<vi> board(n, vi(n));
    for (int i{ 0 }; i < n; ++i) {
        for (int j{ 0 }; j < n; ++j) {
            cin >> board[i][j];
        }
    }
    vector<vector<vi> > dist(n, vector<vi>(n, vi(2 * m, MAX)));
    dist[0][0][0] = 0;
    priority_queue<st> pQ;
    pQ.push({ 0, 0, 0 });
    int xx[]{ -1,0,1,0 };
    int yy[]{ 0,1,0,-1 };
    while (!pQ.empty()) {
        int x{ pQ.top().a };
        int y{ pQ.top().b };
        int d{ pQ.top().d };
        int time = 0;
        if ((d / m) & 1) time = 1;
        pQ.pop();
        if (dist[x][y][d % (2 * m)] < d) continue;
        for (int dir{ 0 }; dir < 4; ++dir) {
            int nx{ x + xx[dir] };
            int ny{ y + yy[dir] };
            if (nx < 0 || nx > n - 1 || ny < 0 || ny > n - 1) continue;
            int nt = time;
            if ((d + 1) % m == 0) nt ^= 1;
            if (board[nx][ny] == 0) {
                if (dist[nx][ny][(d + 1) % (2 * m)] > d + 1) {
                    dist[nx][ny][(d + 1) % (2 * m)] = d + 1;
                    pQ.push({ nx, ny, d + 1 });
                }
            }
            if (time == 1) {
                if (board[nx][ny] == 1) {
                    int a = nx;
                    int b = ny;
                    while (a >= 0 && b >= 0 && a < n && b < n && board[a][b] == 1) {
                        a += xx[dir];
                        b += yy[dir];
                    }
                    if (a < 0 || a > n - 1 || b < 0 || b > n - 1) continue;
                    if (dist[a][b][(d + 1) % (2 * m)] > d + 1) {
                        dist[a][b][(d + 1) % (2 * m)] = d + 1;
                        pQ.push({ a, b, d + 1 });
                    }
                }
            }
        }
    }
    int ans{MAX};
    for(int i{0}; i < 2 * m; ++i){
        ans = min(ans, dist[n - 1][n - 1][i]);
    }
    if (ans == MAX) cout << -1;
    else {
        cout << ans / (m * 2) + 1 << " ";
        if ((ans / m) & 1) cout << "moon";
        else cout << "sun";
    }
}

