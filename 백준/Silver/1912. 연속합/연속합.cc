#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int a[100000];
	int dp[100000];
	int n;
	cin >> n;
	for (int i{ 0 }; i < n; ++i) {
		cin >> a[i];
	}
	dp[0] = a[0];
	int mx{ -1000 };
	for (int i{ 1 }; i < n; ++i) {
		dp[i] = max(dp[i - 1] + a[i], a[i]);
		mx = max(mx, dp[i]);
	}
	mx = max(mx, dp[0]);
	cout << mx;
}