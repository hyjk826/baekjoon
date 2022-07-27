// 2022-07-28
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

vector<vc> board;

void f(int L, int x, int y) {
    if (L == 1) {
        board[x][y] = '*';
    }
    else {
        int a = 1 + 4 * (L - 1);
        for (int j{ y }; j < y + a; ++j) {
            board[x][j] = '*';
            board[x + a - 1][j] = '*';
        }
        for (int i{ x }; i < x + a; ++i) {
            board[i][y] = '*';
            board[i][y + a - 1] = '*';
        }
        f(L - 1, x + 2, y + 2);
    }
}
int main() {
    fastio;
    int n;
    cin >> n;
    int a = 1 + 4 * (n - 1);
    board.resize(a, vc(a, ' '));
    f(n, 0, 0);
    for (int i{ 0 }; i < a; ++i) {
        for (int j{ 0 }; j < a; ++j) {
            cout << board[i][j];
        }
        cout << "\n";
    }
}

