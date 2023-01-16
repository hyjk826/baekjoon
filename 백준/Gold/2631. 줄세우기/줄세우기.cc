#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <set>
#include <stack>
#include <sstream>
#include <cmath>
#include <cstring>
#define pi pair<int, int>
#define vi vector<int>
#define ll long long
#define MAX 2147000000
#define MOD 1234567891
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(0);
	int n;
	cin >> n;
	vector<int> vec(n);
	for (int i{ 0 }; i < n; ++i) {
		cin >> vec[i];
	}
	vector<int> dp(n, 1);
	int ans{ 1 };
	for (int i{ 0 }; i < n; ++i) {
		for (int j{ 0 }; j < i; ++j) {
			if (vec[i] > vec[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		ans = max(ans, dp[i]);
	}
	cout << n - ans;
}