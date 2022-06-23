#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int dp[1001][1001]{};

int main() {
	ios_base::sync_with_stdio(false);
	string str1;
	string str2;
	cin >> str1;
	cin >> str2;
	int s1 = (int)str1.size();
	int s2 = (int)str2.size();
	for (int i{ 1 }; i <= s1; ++i) {
		for (int j{ 1 }; j <= s2; ++j) {
			if (str1[i-1] == str2[j-1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	cout << dp[s1][s2];
}