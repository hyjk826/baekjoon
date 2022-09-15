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

int n, m;
vector<int> graph[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	vector<int> degree(n + 1, 0);
	int cnt;
	int num;
	vector<int> vec;
	for (int i{ 0 }; i < m; ++i) {
		cin >> cnt;
		vec.clear();
		while (cnt--) {
			cin >> num;
			vec.push_back(num);
		}
		for (int i{ 0 }; i < (int)vec.size()-1; ++i) {
			graph[vec[i]].push_back(vec[i + 1]);
			degree[vec[i + 1]]++;
		}
	}
	queue<int> Q;
	for (int i{ 1 }; i <= n; ++i) {
		if (degree[i] == 0) {
			Q.push(i);
		}
	}
	vector<int> ans;
	while (!Q.empty()) {
		int x{ Q.front() };
		ans.push_back(x);
		Q.pop();
		for (int i{ 0 }; i < (int)graph[x].size(); ++i) {
			degree[graph[x][i]]--;
			if (degree[graph[x][i]] == 0) {
				Q.push(graph[x][i]);
			}
		}
	}
	int size = (int)ans.size();
	if (size == n) {
		for (int i{ 0 }; i < n; ++i) {
			cout << ans[i] << "\n";
		}
	}
	else {
		cout << 0;
	}
}
