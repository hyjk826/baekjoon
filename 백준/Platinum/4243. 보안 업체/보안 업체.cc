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
	int n, s;
    cin >> n >> s;
    vl vec(n);
    for(int i{1}; i <= n - 1; ++i){
        cin >> vec[i];
    }
    auto pre = vec;
    for(int i{1}; i <= n - 1; ++i){
        pre[i] += pre[i - 1];
    }
    vector<vector<vl> > dp(n + 1 , vector<vl>(n + 1, vl(2, -1)));
    function<ll(int,int,int)> f = [&](int l, int r, int k){
        if(dp[l][r][k] != -1) return dp[l][r][k];
        if(l == 1 && r == n) return 0LL;
        int cur;
        if(k == 0) cur = l;
        else cur = r;
        ll a = LLONG_MAX;
        ll b = LLONG_MAX;
        if(l != 1){
            a = (pre[cur - 1] - pre[l - 2]) * (n - (r - l + 1)) + f(l - 1, r, 0);
        }
        if(r != n){
            b = (pre[r] - pre[cur - 1]) * (n - (r - l + 1)) + f(l, r + 1, 1);
        }
        return dp[l][r][k] = min(a, b);
    };
    cout << f(s, s, 0) << "\n";
}

int main(){
	fastio;
	int T;
	cin >> T;
	while(T--){
		solve();
	}
}
