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
	int n, k;
	cin >> n >> k;
	vector<int> vec(n);
	for (int i{ 0 }; i < n; ++i) {
		cin >> vec[i];
	}
	vector<int> dp(k + 1);
	dp[0] = 1;
	for (int i{ 0 }; i < n; ++i) {
		for (int j{ 1 }; j <= k; ++j) {
			if (j >= vec[i]) {
				dp[j] += dp[j - vec[i]];
			}
		}
	}
	cout << dp[k];
}