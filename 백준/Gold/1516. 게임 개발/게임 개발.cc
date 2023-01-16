#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <string>
using namespace std;

int n;
int tm[501];
int degree[501];
int ans[501];
vector<int> graph[501];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i{ 1 }; i <= n; ++i) {
		cin >> tm[i];
		int a;
		while (1) {
			cin >> a;
			if (a == -1)
				break;
			graph[a].push_back(i);
			degree[i]++;
		}
	}
	queue<int> Q;
	for (int i{ 1 }; i <= n; ++i) {
		if (degree[i] == 0) {
			Q.push(i);
			ans[i] = tm[i];
		}
	}

	while (!Q.empty()) {
		int x{ Q.front() };
		Q.pop();
		for (int i{ 0 }; i < (int)graph[x].size(); ++i) {
			degree[graph[x][i]]--;
			if (degree[graph[x][i]] == 0) {
				Q.push(graph[x][i]);
			}
			ans[graph[x][i]] = max(ans[graph[x][i]], ans[x] + tm[graph[x][i]]);
		}
	}
	for (int i{ 1 }; i <= n; ++i) {
		cout << ans[i] << "\n";
	}
}