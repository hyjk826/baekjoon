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

vector<pi> vec(500);
vector<vi> dp(500, vi(500, -1));

int fdp(int a, int b) {
	if (a == b) return dp[a][b] = 0;
	if (dp[a][b] != -1) return dp[a][b];
	dp[a][b] = MAX;
	for (int i{ a }; i < b; ++i) {
		dp[a][b] = min(dp[a][b], fdp(a, i) + fdp(i + 1, b) + vec[a].first * vec[i].second * vec[b].second);
	}
	return dp[a][b];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(0);
	int n;
	cin >> n;
	for (int i{ 0 }; i < n; ++i) {
		cin >> vec[i].first >> vec[i].second;
	}
	cout << fdp(0, n - 1);
}