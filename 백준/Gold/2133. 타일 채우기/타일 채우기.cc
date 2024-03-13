#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#define pi pair<int, int>
#define vi vector<int>
#define ll long long
#define MAX 2147000000
#define MOD 10007
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<ll> dp(31);
	dp[0] = 1;
	dp[1] = 0;
	dp[2] = 3;
	dp[3] = 0;
	for (int i{ 4 }; i <= n; ++i) {
		dp[i] = 3 * dp[i - 2];
		for (int j{ 4 }; j <= i; j += 2) {
			dp[i] += dp[i - j] * 2;
		}
	}
	cout << dp[n];
}