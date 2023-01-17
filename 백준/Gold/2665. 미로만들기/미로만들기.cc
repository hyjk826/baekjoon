#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

int n;
int map[101][101]{};
int visit[101][101]{};
int xx[]{ -1,0,1,0 };
int yy[]{ 0,1,0,-1 };

struct edge {
	int x, y, cnt;
	edge(int a, int b, int c) {
		x = a;
		y = b;
		cnt = c;
	}
	bool operator< (const edge& a) const {
		return cnt > a.cnt;
	}
};

int main() {
	cin >>  n;
	for (int i{ 1 }; i <= n; ++i) {
		for (int j{ 1 }; j <= n; ++j) {
			scanf("%1d", &map[i][j]);
		}
	}
	visit[1][1] = 1;
	priority_queue<edge> pQ;
	pQ.push({ 1,1,0 });
	while (!pQ.empty()) {
		edge s{ pQ.top() };
		if (s.x == n && s.y == n) {
			cout << s.cnt;
			return 0;
		}
		pQ.pop();
		for (int i{ 0 }; i < 4; ++i) {
			int nx{ s.x + xx[i] };
			int ny{ s.y + yy[i] };
			if (nx < 1 || nx > n || ny < 1 || ny > n)
				continue;
			if (visit[nx][ny] == 0) {
				visit[nx][ny] = 1;
				if (map[nx][ny] == 1) {
					pQ.push({ nx,ny,s.cnt });
				}
				else if (map[nx][ny] == 0) {
					pQ.push({ nx,ny,s.cnt + 1 });
				}
			}
		}
	}
}