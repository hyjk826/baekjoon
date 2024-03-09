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
    vector<vp> g(n + 1);
    for(int i{0}; i < n - 1; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    vi dp(n + 1, -1);
    function<int(int,int)> f = [&](int cur, int pre){
        if(dp[cur] != -1) return dp[cur];
        int& ret = dp[cur];
        ret = 0;
        for(auto& i : g[cur]){
            if(i.first == pre) continue;
            ret += min(i.second, f(i.first, cur));
        }
        if(ret == 0) ret = MAX;
        return ret;
    };
    cout << f(1, 0) << "\n";
}


int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}