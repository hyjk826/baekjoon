// 2022-09-14
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

vector<int> vec[1001];

int main() {
	fastio;
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		for (int i{ 1 }; i <= n; ++i) {
			vec[i].clear();
		}
		vector<int> time(n + 1);
		for (int i{ 1 }; i <= n; ++i) {
			cin >> time[i];
		}
		vector<int> degree(n + 1);
		for (int i{ 0 }; i < k; ++i) {
			int a, b;
			cin >> a >> b;
			vec[a].push_back(b);
			degree[b]++;
		}
		vector<int> ans(n + 1);
		int w;
		cin >> w;
		queue<int> Q;
		for (int i{ 1 }; i <= n; ++i) {
			if (degree[i] == 0) {
				ans[i] = time[i];
				Q.push(i);
			}
		}
		while (!Q.empty()) {
			int x{ Q.front() };
			Q.pop();
			if (x == w) break;
			for (int i{ 0 }; i < (int)vec[x].size(); ++i) {
				int nx{ vec[x][i] };
				degree[nx]--;				
                ans[nx] = max(ans[nx], ans[x] + time[nx]);
				if (degree[nx] == 0) {                    
					Q.push(nx);
				}
			}
		}
		cout << ans[w] << "\n";
	}
}
	

