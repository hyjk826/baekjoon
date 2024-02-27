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
#define MOD 998244353
using namespace std; 


void solve(){
	int h, w, n, t;
	cin >> h >> w >> n >> t;
	ll ans{1};
	for(int i{0}; i < n; ++i){
		int a, b;
		cin >> a >> b;
		int aa = min(h, a + t) - max(1, a - t) + 1;
		int bb = min(w, b + t) - max(1, b - t) + 1;
		ans *= (1LL * aa * bb) % MOD;
		ans %= MOD;
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