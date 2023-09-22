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
	int n, m, k;
    cin >> n >> m >> k;
    vector<vi> dp(m + 1, vi(k));
    vi vec(n);
    for(auto& i : vec) cin >> i;
    dp[0][0] = 1;
    for(int i{1}; i <= m; ++i){
        for(int j{0}; j < k; ++j){
            for(auto& a : vec){
                if(i == 1 && a == 0) continue;
                dp[i][(j * 10 + a) % k] += dp[i - 1][j];
                dp[i][(j * 10 + a) % k] %= MOD;
            }
        }
    }
    cout << dp[m][0] << "\n";
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
