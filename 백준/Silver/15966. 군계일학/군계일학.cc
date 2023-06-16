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

int dp[1000001];

void solve(){
    int n;
    cin >> n;
    int ans{0};
    for(int i{0}; i < n; ++i){
        int a;
        cin >> a;
        dp[a] = max({dp[a], dp[a - 1] + 1, 1});
        ans = max(ans, dp[a]);
    }
    cout << ans;
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
