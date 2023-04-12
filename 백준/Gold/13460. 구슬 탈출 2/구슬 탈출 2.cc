#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <string>
using namespace std;

char map[10][10];
int n, m;
int rx, ry;
int bx, by;
int xx[]{ -1,0,1,0 };
int yy[]{ 0,1,0,-1 };
int visit[10][10][10][10]{};

struct edge {
	int rx, ry, bx, by, cnt;
	edge(int a, int b, int c, int d, int e) {
		rx = a;
		ry = b;
		bx = c;
		by = d;
		cnt = e;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	edge s(0, 0, 0, 0, 0);
	for (int i{ 0 }; i < n; ++i) {
		for (int j{ 0 }; j < m; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 'R') {
				s.rx = i;
				s.ry = j;
				map[i][j] == '.';
			}
			else if(map[i][j] == 'B'){
				s.bx = i;
				s.by = j;
				map[i][j] = '.';
			}
		}
	}
	s.cnt = 0;
	queue<edge> Q;
	visit[s.rx][s.ry][s.bx][s.by] = 1;
	Q.push(s);
	int ans{ -1 };
	while (!Q.empty()) {
		edge x = Q.front();
		Q.pop();
		if (map[x.bx][x.by] == 'O') continue;
		if (x.cnt > 10) break;
		if (map[x.rx][x.ry] == 'O' && map[x.bx][x.by] != 'O') {
			ans = x.cnt;
			break;
		}
		for (int i{ 0 }; i < 4; ++i) {
			int nrx{ x.rx };
			int nry{ x.ry };
			int nbx{ x.bx };
			int nby{ x.by };
			while (1) {
				nrx += xx[i];
				nry += yy[i];
				if (map[nrx][nry] == '#') {
					nrx -= xx[i];
					nry -= yy[i];
					break;
				}
				else if (map[nrx][nry] == 'O') {
					break;
				}
			}
			while (1) {
				nbx += xx[i];
				nby += yy[i];
				if (map[nbx][nby] == '#') {
					nbx -= xx[i];
					nby -= yy[i];
					break;
				}
				else if (map[nbx][nby] == 'O') {
					break;
				}
			}
			if (nrx == nbx && nry == nby) {
				if (map[nrx][nry] != 'O') {
					int rm = abs(nrx - x.rx) + abs(nry - x.ry);
					int bm = abs(nbx - x.bx) + abs(nby - x.by);
					if (rm > bm) {
						nrx -= xx[i];
						nry -= yy[i];
					}
					else {
						nbx -= xx[i];
						nby -= yy[i];
					}
				}
			}
			if (visit[nrx][nry][nbx][nby] == 0) {
				visit[nrx][nry][nbx][nby] = 1;
				Q.push({ nrx,nry,nbx,nby,x.cnt + 1 });
			}
		}
	}
	cout << ans;
}
