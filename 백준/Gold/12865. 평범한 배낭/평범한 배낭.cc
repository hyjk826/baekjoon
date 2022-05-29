// 2022-05-29
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int main(){
    fastio;
	int n, k;
	cin >> n >> k;
	vector<int> dp(k + 1);
	for (int i{ 0 }; i < n; ++i) {
		int w, v;
		cin >> w >> v;
		for (int j{ k }; j >= w; --j) {
			dp[j] = max(dp[j], dp[j - w] + v);
		}
	}
	cout << dp[k];
}