// 2022-09-13
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
    int x, y, k; // 가로 0 세로 1 대각 2;
};

int main(){
    fastio;
    int n;
    cin >> n;
    vector<vi> board(n, vi(n));
    for (int i{ 0 }; i < n; ++i) {
        for (int j{ 0 }; j < n; ++j) {
            cin >> board[i][j];
        }
    }
    int ans{ 0 };
    queue<st> Q;
    Q.push({ 0,1,0});
    int xx[]{ 0,1,1 };
    int yy[]{ 1,0,1 };
    while (!Q.empty()) {
        int x{ Q.front().x };
        int y{ Q.front().y };
        int k{ Q.front().k };
        Q.pop();
        if (x == n - 1 && y == n - 1) {
            ans++;
        }
        for (int i{ 0 }; i < 3; ++i) {
            int nx{ x + xx[i] };
            int ny{ y + yy[i] };
            if (nx > n - 1 || ny > n - 1) continue;
            if (i == 0) {
                if (k != 1 && board[nx][ny] == 0) {
                    Q.push({ nx,ny,0 });
                }
            }
            else if (i == 1) {
                if (k != 0 && board[nx][ny] == 0) {
                    Q.push({ nx,ny,1 });
                }
            }
            else{
                if (board[nx - 1][ny] == 0 && board[nx][ny - 1] == 0 && board[nx][ny] == 0) {
                    Q.push({ nx, ny, 2 });
                }
            }
        }
    }
    cout << ans;
}
	

