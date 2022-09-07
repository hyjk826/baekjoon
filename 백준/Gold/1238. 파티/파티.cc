#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#define pi pair<int, int>
#define vi vector<int>
#define ll long long
#define MAX 214700000
using namespace std;

int xx[]{ -1,0,1,0 };
int yy[]{ 0,1,0,-1 };

struct edge {
	int v, dis;
	bool operator< (const edge& a) const {
		return dis > a.dis;
	}
};

vector<edge> map[1001];
vector<edge> map2[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, x;
	cin >> n >> m >> x;
	for (int i{ 0 }; i < m; ++i) {
		int a, b, dis;
		cin >> a >> b >> dis;
		map[a].push_back({ b,dis });
		map2[b].push_back({ a,dis });
	}
	vector<int> dijk(n + 1, MAX);
	vector<int> dijk2(n + 1, MAX);
	dijk[x] = 0;
	priority_queue<edge> pQ;
	pQ.push({ x,0 });
	while (!pQ.empty()) {
		int v{ pQ.top().v };
		int dis{ pQ.top().dis };
		pQ.pop();
		if (dis > dijk[v]) continue;
		for (int i{ 0 }; i < (int)map[v].size(); ++i) {
			int nx{ map[v][i].v };
			int ndis{ map[v][i].dis };
			if (dis + ndis < dijk[nx]) {
				dijk[nx] = dis + ndis;
				pQ.push({ nx, dijk[nx] });
			}
		}
	}
	dijk2[x] = 0;
	pQ.push({ x,0 });
	while (!pQ.empty()) {
		int v{ pQ.top().v };
		int dis{ pQ.top().dis };
		pQ.pop();
		if (dis > dijk2[v]) continue;
		for (int i{ 0 }; i < (int)map2[v].size(); ++i) {
			int nx{ map2[v][i].v };
			int ndis{ map2[v][i].dis };
			if (dis + ndis < dijk2[nx]) {
				dijk2[nx] = dis + ndis;
				pQ.push({ nx, dijk2[nx] });
			}
		}
	}
	int mx{ 0 };
	for (int i{ 1 }; i <= n; ++i) {
		mx = max(mx, dijk[i] + dijk2[i]);
	}
	cout << mx;
}