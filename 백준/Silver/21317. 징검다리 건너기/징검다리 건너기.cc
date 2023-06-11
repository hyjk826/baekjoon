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
    vp vec(n - 1);
    for(int i{0}; i < n - 1; ++i){
        cin >> vec[i].first >> vec[i].second;
    }
    int k;
    cin >> k;
    vector<vi> dp(n, vi(2, -1));
    function<int(int, int)> f = [&](int a, int b){
        if(a == n - 1) return 0;
        if(a > n - 1) return MAX;
        if(dp[a][b] != -1) return dp[a][b];
        dp[a][b] = MAX;
        dp[a][b] = min(dp[a][b], vec[a].first + f(a + 1, b));
        dp[a][b] = min(dp[a][b], vec[a].second + f(a + 2, b));
        if(b == 0) dp[a][b] = min(dp[a][b], k + f(a + 3, 1));
        return dp[a][b];
    };
    cout << f(0, 0) << "\n";
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
