#define MAX 2147000000
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

vector<pair<int, int> > vec[201];
int n, m;
int p[201]{};

struct edge {
	int v;
	int dis;
	edge(int a, int b) {
		v = a;
		dis = b;
	}
	bool operator< (const edge& a) const {
		return dis > a.dis;
	}
};

void dijkstra(int a) {
	priority_queue<edge> pQ;
	vector<int> dist(n + 1, MAX);
	pQ.push({ a,0 });
	dist[a] = 0;
	while (!pQ.empty()) {
		int x{ pQ.top().v };
		int dis{ pQ.top().dis };
		pQ.pop();
		if (dis > dist[x]) continue;
		for (int i{ 0 }; i < (int)vec[x].size(); ++i) {
			if (dis + vec[x][i].second < dist[vec[x][i].first]) {
				p[vec[x][i].first] = x;
				dist[vec[x][i].first] = dis + vec[x][i].second;
				pQ.push({ vec[x][i].first, dist[vec[x][i].first] });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i{ 0 }; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		vec[a].push_back({ b,c });
		vec[b].push_back({ a,c });
	}
	vector<vector<string> > ans(n + 1, vector<string>(n + 1, "-"));
	for (int i{ 1 }; i <= n; ++i) {
		dijkstra(i);
		for (int j{ 1 }; j <= n; ++j) {
			if (i == j) continue;
			for (int k{ j };; k = p[k]) {
				if (p[k] == i) {
					ans[i][j] = to_string(k);
					break;
				}
			}
		}
	}
	for (int i{ 1 }; i <= n; ++i) {
		for (int j{ 1 }; j <= n; ++j) {
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
}