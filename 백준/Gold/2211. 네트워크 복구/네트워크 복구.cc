#define MAX 2147000000
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int> > vec[1001];
int n, m;
int p[1001]{};

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

void dijkstra() {
	priority_queue<edge> pQ;
	vector<int> dist(n + 1, MAX);
	pQ.push({ 1,0 });
	dist[1] = 0;
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
	dijkstra();
	vector<pair<int, int> > ans;
	for (int i{ 2 }; i <= n; ++i) {
		ans.push_back({ i, p[i] });
	}
	cout << ans.size() << "\n";
	for (int i{ 0 }; i < (int)ans.size(); ++i) {
		cout << ans[i].first << " " << ans[i].second << "\n";
	}	
}