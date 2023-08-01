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
    vi vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    vi dp(n, -1);
    function<int(int)> f = [&](int x){
        if(x >= n) return 0;
        int& ret = dp[x];
        if(ret != -1) return ret;
        if(x == n - 1) return ret = -MAX;
        ret = 0;
        int sum{0};
        for(int i{x}; i <= x + 1; ++i){
            sum ^= vec[i];
        }
        ret = max(ret, __builtin_popcount(sum) + f(x + 2));
        if(x + 2 <= n - 1) sum ^= vec[x + 2];
        ret = max(ret, __builtin_popcount(sum) + f(x + 3));
        return ret;
    };
    int ans = max(0, f(0));
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
