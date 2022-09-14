// 2022-09-14
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

bool ch1[21]{};
bool ch2[21]{};
vector<vi> board;
int ans[2]{};
int n;

void dfs(int L, int x, int y, int k) {
	ans[k] = max(ans[k], L);
	if (y >= n) {
		x++;
		if (y % 2 == 0) y = 1;
		else y = 0;
	}
	if (x >= n) return;
	if (board[x][y] && !ch1[x - y + n] && !ch2[x + y]) {
		ch1[x - y + n] = ch2[x + y] = 1;
		dfs(L + 1, x, y + 2, k);
		ch1[x - y + n] = ch2[x + y] = 0;
	}
	dfs(L , x, y + 2, k);
}

int main() {
    fastio;
	cin >> n;
	board.resize(n, vi(n));
	for (int i{ 0 }; i < n; ++i) {
		for (int j{ 0 }; j < n; ++j) {
			cin >> board[i][j];
		}
	}
	dfs(0, 0, 0, 0);
	dfs(0, 0, 1, 1);
	cout << ans[0] + ans[1];
}
	

