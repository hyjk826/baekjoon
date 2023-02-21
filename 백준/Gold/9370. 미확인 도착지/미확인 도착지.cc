#include <iostream>
#include <queue>
#include <string>
#include <stack>
#include <algorithm>
#include <cmath>
#include <set>
#include <unordered_set>
#define vi vector<int>
#define pi pair<int, int>
#define ll long long
#define MAX 2147000000
#define MOD 998244353
using namespace std;

struct edge {
	int v, dis;
	bool operator< (const edge& a) const{
		return dis > a.dis;
	}
};
vector<edge> graph[2001];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int n, m, t, s, g, h;
		cin >> n >> m >> t >> s >> g >> h;
		for (int i{ 1 }; i <= n; ++i) {
			graph[i].clear();
		}
		for (int i{ 0 }; i < m; ++i) {
			int a, b, dis;
			cin >> a >> b >> dis;
			if ((a == g && b == h) || (a == h && b == g)) {
				graph[a].push_back({ b, 2 * dis -1});
				graph[b].push_back({ a, 2 * dis -1 });
			}
			else {
				graph[a].push_back({ b, dis * 2});
				graph[b].push_back({ a, dis * 2});
			}
			
		}
		vector<pi> dijk(n + 1, { MAX, 0 });
		dijk[s].first = 0;
		priority_queue<edge> Q;
		Q.push({ s, 0 });
		while (!Q.empty()) {
			int x{ Q.top().v };
			int dis{ Q.top().dis };
			Q.pop();
			if (dijk[x].first < dis) continue;
			for (int i{ 0 }; i < (int)graph[x].size(); ++i) {
				int nx{ graph[x][i].v };
				int ndis{ graph[x][i].dis };
				if (ndis + dis < dijk[nx].first) {
					dijk[nx].second = dijk[x].second;
					if ((x == g && nx ==h) || (x == h && nx == g)) dijk[nx].second = 1;
					dijk[nx].first = ndis + dis;
					Q.push({ nx, dijk[nx].first });
				}
			}
		}
		vector<int> ans;
		for (int i{ 0 }; i < t; ++i) {
			int a;
			cin >> a;
			if (dijk[a].first % 2 == 1) ans.push_back(a);
		}
		sort(ans.begin(), ans.end());
		for (int i{ 0 }; i < (int)ans.size(); ++i) {
			cout << ans[i] << " ";
		}
		cout << "\n";
	}
}