// 2022-08-25
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

struct st {
    int a, b, c, d, cnt;
};

int ch[21][21][21][21];

int main() {
    fastio;
    int n, m;
    cin >> n >> m;
    int x1, y1, x2, y2;
    x1 = y1 = x2 = y2 = -1;
    vector<vc> board(n, vc(m));
    for (int i{ 0 }; i < n; ++i) {
        for (int j{ 0 }; j < m; ++j) {
            cin >> board[i][j];
            if (board[i][j] == 'o') {
                board[i][j] = '.';
                if (x1 == -1) {
                    x1 = i;
                    y1 = j;
                }
                else {
                    x2 = i;
                    y2 = j;
                }
            }
        }
    }
    for (int i{ 0 }; i < 21; ++i) {
        for (int j{ 0 }; j < 21; ++j) {
            for (int k{ 0 }; k < 21; ++k) {
                for (int l{ 0 }; l < 21; ++l) {
                    ch[i][j][k][l] = -1;
                }
            }
        }
    }
    ch[x1][y1][x2][y2] = 0;
    queue<st> Q;
    Q.push({ x1, y1, x2, y2, 0 });
    int xx[]{ -1,0,1,0 };
    int yy[]{ 0,1,0,-1 };
    while (!Q.empty()) {
        int x1{ Q.front().a };
        int y1{ Q.front().b };
        int x2{ Q.front().c };
        int y2{ Q.front().d };
        int cnt{ Q.front().cnt };
        Q.pop();
        if (cnt == 10) continue;
        for (int dir{ 0 }; dir < 4; ++dir) {
            int nx1{ x1 + xx[dir] };
            int ny1{ y1 + yy[dir] };
            int nx2{ x2 + xx[dir] };
            int ny2{ y2 + yy[dir] };
            int c{ 0 };
            if (nx1 < 0 || nx1 > n - 1 || ny1 < 0 || ny1 > m - 1) c++;
            if (nx2 < 0 || nx2 > n - 1 || ny2 < 0 || ny2 > m - 1) c++;
            
            if (c == 1) {
                cout << cnt + 1;
                return 0;
            }
            
            if (c == 2) continue;
            if (board[nx1][ny1] == '#') {
                nx1 -= xx[dir];
                ny1 -= yy[dir];
            }
            if (board[nx2][ny2] == '#') {
                nx2 -= xx[dir];
                ny2 -= yy[dir];
            }
            if (nx1 == nx2 && ny1 == ny2) continue;
            if (ch[nx1][ny1][nx2][ny2] == -1) {
                ch[nx1][ny1][nx2][ny2] = cnt + 1;                
                Q.push({ nx1, ny1, nx2, ny2, cnt + 1 });
            }
        }
    }
    cout << -1;
}

