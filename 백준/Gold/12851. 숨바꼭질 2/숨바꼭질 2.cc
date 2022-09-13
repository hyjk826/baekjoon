// 2022-09-13
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

int main() {
	fastio;
	int n, k;
	cin >> n >> k;
	vector<pi> ans(100001, { -1,0 });
	queue<pi> Q;
	Q.push({ n, 0 });
	ans[n] = { 0, 1 };
	while (!Q.empty()) {
		int x{ Q.front().first };
		int cnt{ Q.front().second };
		Q.pop();
		for (int i{ 0 }; i < 3; ++i) {
			int nx;
			if (i == 0) {
				nx = x - 1;
			}
			else if (i == 1) {
				nx = x + 1;
			}
			else {
				nx = x * 2;
			}
			if (nx < 0 || nx > 100000) continue;
			if (ans[nx].first == -1) {
				ans[nx] = { cnt + 1, 1 };
				Q.push({ nx, ans[nx].first });
			}
			else {
				if (cnt + 1 == ans[nx].first) {
					ans[nx].second++;
					Q.push({ nx, ans[nx].first });
				}
			}
		}
	}
	cout << ans[k].first << "\n" << ans[k].second;
}
	

