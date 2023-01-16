#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int map[500][500];
int m, n;
int dp[500][500];
int xx[]{ -1,0,1,0 };
int yy[]{ 0,1,0,-1 };
int r;

int DP(int x, int y) {
	if (dp[x][y] != -1)
		return dp[x][y];
	if (x == m - 1 && y == n - 1)
		return 1;
	dp[x][y] = 0;
	for (int i{ 0 }; i < 4; ++i) {
		int nx{ x + xx[i] };
		int ny{ y + yy[i] };
		if (nx < 0 || nx > m - 1 || ny < 0 || ny > n - 1)
			continue;
		if (map[nx][ny] < map[x][y])
			dp[x][y] += DP(nx, ny);
	}
	return dp[x][y];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> m >> n;
	memset(dp, -1, sizeof(dp));
	for (int i{ 0 }; i < m; ++i) {
		for (int j{ 0 }; j < n; ++j) {
			cin >> map[i][j];
		}
	}
	cout << DP(0, 0);
}