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
#define vpl vector<pl>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std; 

void solve(){
	int n;
    cin >> n;
    vp vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i].first >> vec[i].second;
    }
    vector<vi> dp(n, vi(2, (int)1e9));
    dp[0][1] = 0;
    for(int i{1}; i < n; ++i){
        if(i >= 2) dp[i][0] = min(dp[i - 1][0] + abs(vec[i - 1].first - vec[i].first) + abs(vec[i - 1].second - vec[i].second), dp[i - 2][1] + abs(vec[i - 2].first - vec[i].first) + abs(vec[i - 2].second - vec[i].second));
        dp[i][1] = dp[i - 1][1] + abs(vec[i - 1].first - vec[i].first) + abs(vec[i - 1].second - vec[i].second);
    }
    cout << min(dp[n - 1][0], dp[n - 1][1]) << "\n";
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
