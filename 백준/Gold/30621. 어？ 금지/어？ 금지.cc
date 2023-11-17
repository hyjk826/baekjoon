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
    vi T(n + 1), B(n + 1), C(n + 1);
    for(int i{1}; i <= n; ++i){
        cin >> T[i];
    }
    for(int i{1}; i <= n; ++i){
        cin >> B[i];
    }
    for(int i{1}; i <= n; ++i){
        cin >> C[i];
    }
    vector<vl> dp(n + 1, vl(2));
    ll ans{0};
    for(int i{1}; i <= n; ++i){
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
        int idx = lower_bound(T.begin(), T.end(), T[i] - B[i]) - T.begin();
        idx--;
        if(idx == -1) dp[i][1] = C[i];
        else dp[i][1] = max(dp[idx][0], dp[idx][1]) + C[i];
        ans = max(ans, dp[i][0]);
        ans = max(ans, dp[i][1]);
    }
    cout << ans << "\n";
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
