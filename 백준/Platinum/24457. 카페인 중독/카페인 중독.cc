// 2022-12-08
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

int main() {
	fastio;
	int n;
    cin >> n;
    vpl vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i].first;
    }
    for(int i{0}; i < n; ++i){
        cin >> vec[i].second;
    }
    sort(vec.begin(), vec.end(), [&](pi a, pi b){
        return a.second < b.second;
    });
    vector<vl> dp(n + 2, vl(n + 2));
    ll ans{0};
    for(int i{n}; i >= 1; --i){
        for(int j{1}; j <= n; ++j){
            dp[i][j] = max(dp[i + 1][j], dp[i][j]);
            dp[i][j] = max(dp[i][j], dp[i + 1][j - 1] + vec[i - 1].first - vec[i - 1].second * (j - 1));
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans;
}
	
