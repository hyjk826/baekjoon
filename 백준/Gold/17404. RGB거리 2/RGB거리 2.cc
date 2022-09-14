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

int RGB[1000][3];
int DP[1000][3];

int main() {
	fastio;
	int n;
	cin >> n;
	for (int i{ 0 }; i < n; ++i) {
		cin >> RGB[i][0] >> RGB[i][1] >> RGB[i][2];
	}
	int mn{ MAX };
	for (int j{ 0 }; j < 3; ++j) {
		for (int i{ 0 }; i < 3; ++i) {
			if (i == j) {
				DP[0][i] = RGB[0][i];
			}
			else {
				DP[0][i] = MAX;
			}
		}
		for (int i{ 1 }; i < n; ++i) {
			DP[i][0] = RGB[i][0] + min(DP[i - 1][1], DP[i - 1][2]);
			DP[i][1] = RGB[i][1] + min(DP[i - 1][0], DP[i - 1][2]);
			DP[i][2] = RGB[i][2] + min(DP[i - 1][0], DP[i - 1][1]);
		}
		for (int i{ 0 }; i < 3; ++i) {
			if (i == j) {
				continue;
			}
			mn = min(mn, DP[n - 1][i]);
		}
	}
	cout << mn;
}
	

