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

struct st{
    int v, c, d;
};

void solve(){
	int n, k, m;
    cin >> n >> k >> m;
    vector<vector<st>> g(n + 1);
    for(int i{0}; i < m; ++i){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        g[a].push_back({b, c, d});
    }
    vector<vi> dp(n + 1, vi(k + 1, -1));
    function<int(int,int)> f = [&](int a, int b){
        if(dp[a][b] != -1) return dp[a][b];
        int& ret = dp[a][b];
        if(a == n) return ret = 0;
        ret = MAX;
        for(auto& i : g[a]){
            if(b + i.c > k) continue;
            ret = min(ret, i.d + f(i.v, b + i.c)); 
        }
        return ret;
    };
    int ans = f(1, 0);
    if(ans == MAX) cout << "Poor KCM\n";
    else cout << ans << "\n";
}

int main(){
	fastio;
	int T;
	cin >> T;
	while(T--){
		solve();
	}
}
