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

ll dp[1002][1002][2];

void solve(){
	int n, s;
    cin >> n >> s;
    vl vec(n + 2);
    for(int i{1}; i <= n; ++i){
        cin >> vec[i];
    }
    vec[n + 1] = s;
    sort(vec.begin(), vec.end());
    s = lower_bound(vec.begin(), vec.end(), s) - vec.begin();
    memset(dp, -1, sizeof(dp));
    function<ll(int,int,int)> f = [&](int l, int r, int k){
        if(dp[l][r][k] != -1) return dp[l][r][k];
        if(l == 1 && r == n + 1) return 0LL;
        int cur;
        if(k == 0) cur = l;
        else cur = r;
        ll a = LLONG_MAX;
        ll b = LLONG_MAX;
        if(l != 1){
            a = (vec[cur] - vec[l - 1]) * (n + 1 - (r - l + 1)) + f(l - 1, r , 0);
        }
        if(r != n + 1){
            b = (vec[r + 1] - vec[cur]) * (n + 1 - (r - l + 1)) + f(l, r + 1, 1);
        }
        return dp[l][r][k] = min(a, b);
    };
    cout << f(s, s, 0) << "\n";
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
