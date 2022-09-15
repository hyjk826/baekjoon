// 2022-09-15
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

int xx[]{ -1,0,1,0 };
int yy[]{ 0,1,0,-1 };

struct edge {
	int rx, ry, bx, by, cnt;
};
int ch[10][10][10][10]{};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	edge s;
	s.cnt = 0;
	queue<edge> Q;
	vector<vector<char> > map(n, vector<char>(m));
	for (int i{ 0 }; i < n; ++i) {
		for (int j{ 0 }; j < m; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 'R') {
				s.rx = i;
				s.ry = j;
				map[i][j] = '.';
			}
			else if (map[i][j] == 'B') {
				s.bx = i;
				s.by = j;
				map[i][j] = '.';
			}
		}
	}
	Q.push(s);
	ch[s.rx][s.ry][s.bx][s.by] = 1;
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
			if (ch[nrx][nry][nbx][nby] == 0) {
				ch[nrx][nry][nbx][nby] = 1;
				Q.push({ nrx,nry,nbx,nby,x.cnt + 1 });
			}
		}
	}
	cout << ans;
}

