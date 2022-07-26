// 2022-07-25
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
    string s, t;
    cin >> s >> t;
    vector<vi> dp((int)s.size(), vi((int)t.size()));
	int ans{0};
	for(int i{0}; i < (int)s.size(); ++i){
		for(int j{0}; j < (int)t.size(); ++j){
			if(s[i] == t[j]){
				dp[i][j] = 1;
				if(i && j) dp[i][j] += dp[i - 1][j - 1];
				ans = max(ans, dp[i][j]);
			}
		}
	}
	cout << ans;
}

