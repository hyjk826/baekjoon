#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct st {
	int x, y, state, cnt;
};
bool ch[2][1000][1000]{};

int xx[]{ -1,0,1,0 };
int yy[]{ 0,1,0,-1 };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<int> > map(n, vector<int>(m));
	for (int i{ 0 }; i < n; ++i) {
		for (int j{ 0 }; j < m; ++j) {
			char a;
			cin >> a;
			map[i][j] = a - '0';
		}
	}
	queue<st> Q;
	Q.push({ 0,0,0,1 });
	ch[0][0][0] = 1;
	while (!Q.empty()) {
		int x{ Q.front().x };
		int y{ Q.front().y };
		int state{ Q.front().state };
		int cnt{ Q.front().cnt };
		Q.pop();
		if (x == n - 1 && y == m - 1) {
			cout << cnt;
			return 0;
		}
		for (int i{ 0 }; i < 4; ++i) {
			int nx{ x + xx[i] };
			int ny{ y + yy[i] };
			if (nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1) continue;
			if (map[nx][ny] == 0) {
				if (ch[state][nx][ny] == 0) {
					ch[state][nx][ny] = 1;
					Q.push({ nx, ny, state, cnt + 1 });
				}
			}
			else {
				if (state == 0 && ch[1][nx][ny] == 0) {
					ch[1][nx][ny] = 1;
					Q.push({ nx,ny, 1, cnt + 1 });
				}
			}
		}
	}
	cout << -1;
}