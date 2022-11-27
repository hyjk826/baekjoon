// 2022-11-26
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

int n, m;
vi H(10001);
vector<vi> g(10001);
vector<vi> dp(10001, vi(501, -1));

int f(int a, int b){
    if(dp[a][b] != -1) return dp[a][b];
    if(b == 0) return dp[a][b] = H[a];
    if(b > 0 && g[a].size() == 0) return dp[a][b] = MAX;
    dp[a][b] = MAX;
    for(auto& i : g[a]){
        dp[a][b] = min(dp[a][b], f(i, b - 1));
    }
    return dp[a][b];
}


int main() {
	fastio;
    cin >> n >> m;
    for(int i{1}; i <= n; ++i) cin >> H[i];
    for(int i{0}; i < m; ++i){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int q;
    cin >> q;
    while(q--){
        int a, b;
        cin >> a >> b;
        int ans = f(a, b);
        if(ans == MAX) cout << -1 << "\n";
        else cout << ans << "\n";
    }
}
	
