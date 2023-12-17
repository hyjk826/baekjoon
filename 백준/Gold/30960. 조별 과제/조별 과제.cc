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
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    vl dp(n, -1);
    function<ll(int)> f = [&](int a){
        if(a == n) return 0LL;
        if(a == n - 1 || a > n) return (ll)1e18;
        if(dp[a] != -1) return dp[a];
        ll& ret = dp[a];
        ret = vec[a + 1] - vec[a] + f(a + 2);
        if(a % 2 == 0 && a <= n - 3) ret = min(ret, vec[a + 2] - vec[a] + f(a + 3));
        return ret; 
    };
    cout << f(0) << "\n";
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
