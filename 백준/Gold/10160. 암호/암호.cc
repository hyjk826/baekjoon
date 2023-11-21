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
#define MOD 1000000009
using namespace std; 

ll dp[1000001];

void solve(){
    int n, k;
    cin >> n >> k;
    dp[0] = 1;
    for(int i{1}; i <= n; ++i){
        dp[i] = dp[i - 1] * k; 
        if(i >= 5) dp[i] = (dp[i] - dp[i - 5] * 2 + 2 * MOD) % MOD;
        if(i >= 7) dp[i] += dp[i - 7];
        dp[i] %= MOD;
    }
    cout << dp[n] << "\n";
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
