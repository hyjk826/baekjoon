// 2022-07-16
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define pi pair<int, int>
#define pl pair<ll, ll>
#define vp vector<pi>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int main() {
    fastio;
    int n, m, x, y, q;
    cin >> n >> m >> x >> y >> q;
    vector<vi> board(n, vi(m));
    for (int i{ 0 }; i < n; ++i) {
        for (int j{ 0 }; j < m; ++j) {
            cin >> board[i][j];
        }
    }
    vi vec(6);
    while (q--) {
        int a;
        cin >> a;
        if (a == 1) { // 동
            if (y < m - 1) {
                vi v = { 0, 2, 5, 3 };
                int k = vec[v.back()];
                for (int i{ 3 }; i >= 1; --i) {
                    vec[v[i]] = vec[v[i - 1]];
                }
                vec[0] = k;
                y++;
                if (board[x][y] != 0) {
                    vec[5] = board[x][y];
                    board[x][y] = 0;
                }
                else {
                    board[x][y] = vec[5];
                }
                cout << vec[0] << "\n";
            }
        }
        else if (a == 2) { // 서
            if (y > 0) {
                vi v = { 0, 3, 5, 2 };
                int k = vec[v.back()];
                for (int i{ 3 }; i >= 1; --i) {
                    vec[v[i]] = vec[v[i - 1]];
                }
                vec[0] = k;
                y--;
                if (board[x][y] != 0) {
                    vec[5] = board[x][y];
                    board[x][y] = 0;
                }
                else {
                    board[x][y] = vec[5];
                }
                cout << vec[0] << "\n";
            }
        }
        else if (a == 3) { // 북
            if (x > 0) {
                vi v = { 0, 1, 5, 4 };
                int k = vec[v.back()];
                for (int i{ 3 }; i >= 1; --i) {
                    vec[v[i]] = vec[v[i - 1]];
                }
                vec[0] = k;
                x--;
                if (board[x][y] != 0) {
                    vec[5] = board[x][y];
                    board[x][y] = 0;
                }
                else {
                    board[x][y] = vec[5];
                }
                cout << vec[0] << "\n";
            }
        }
        else { // 남
            if (x < n - 1) {
                vi v = { 0, 4, 5, 1 };
                int k = vec[v.back()];
                for (int i{ 3 }; i >= 1; --i) {
                    vec[v[i]] = vec[v[i - 1]];
                }
                vec[0] = k;
                x++;
                if (board[x][y] != 0) {
                    vec[5] = board[x][y];
                    board[x][y] = 0;
                }
                else {
                    board[x][y] = vec[5];
                }
                cout << vec[0] << "\n";
            }
        }
    }
}
