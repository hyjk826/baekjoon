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
#define MAX 2147000000
#define MOD 1000000007
typedef long long ll;
using namespace std;

void solve(){
	int n;
    cin >> n;
    vi vec(n);
    for(auto& i : vec) cin >> i;
    vl dp(n, LLONG_MAX);
    dp[0] = 0;
    for(int i{1}; i < n; ++i){
        for(int j{0}; j < i; ++j){
            dp[i] = min(dp[i], max(dp[j], 1LL * (i - j) * (1 + abs(vec[i] - vec[j]))));
        }
    }
    cout << dp.back() << "\n";
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
