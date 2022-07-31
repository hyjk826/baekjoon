// 2022-07-31
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

int xx[]{ -1,-1,0,1,1,1,0,-1 };
int yy[]{ 0,-1,-1,-1,0,1,1,1 };
int ans{ 0 };

void dfs(vector<vp> board, int x, int y, int sum) {
    ans = max(ans, sum);
    vp l(17, { -2,-2 });
    for (int i{ 0 }; i < 4; ++i) {
        for (int j{ 0 }; j < 4; ++j) {
            if (board[i][j].first == -1) continue;
            l[board[i][j].first] = { i, j };
        }
    }
    for (int i{ 1 }; i <= 16; ++i) {
        if (l[i].first == -2) continue;
        int a = l[i].first;
        int b = l[i].second;
        int d = board[a][b].second;
        for (int dir{ d }, cnt{ 0 }; cnt < 8; ++cnt, dir = (dir + 1) % 8) {
            int nx = a + xx[dir];
            int ny = b + yy[dir];
            if (nx < 0 || nx > 3 || ny < 0 || ny > 3) continue;
            if (board[nx][ny].first > 0) {
                l[board[nx][ny].first] = { a, b };
                l[board[a][b].first] = { nx, ny };
                board[a][b].second = dir;
                swap(board[nx][ny], board[a][b]);
                break;
            }
            else if (board[nx][ny].first == -1) {
                board[a][b].second = dir;
                swap(board[nx][ny], board[a][b]);
                break;
            }
        }
    }
    int dir = board[x][y].second;
    int a = x;
    int b = y;
    while (1) {
        a += xx[dir];
        b += yy[dir];
        if (a < 0 || a > 3 || b < 0 || b > 3) break;
        if (board[a][b].first > 0) {
            vector<vp> copy = board;
            copy[x][y].first = -1;
            int s = copy[a][b].first;
            copy[a][b].first = 0;
            dfs(copy, a, b, sum + s);
        }
    }
}


int main() {
    fastio;
    vector<vp> board(4, vp(4));
    for (int i{ 0 }; i < 4; ++i) {
        for (int j{ 0 }; j < 4; ++j) {
            cin >> board[i][j].first >> board[i][j].second;
            board[i][j].second--;
        }
    }
    int s = board[0][0].first;
    board[0][0].first = 0;
    dfs(board, 0, 0, s);
    cout << ans;
}

