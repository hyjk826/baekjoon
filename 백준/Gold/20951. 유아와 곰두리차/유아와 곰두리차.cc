// 2022-09-18
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
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int n, m;
vector<vi> g(100001);
vector<vi> dp(100001, vi(8, -1));
int ans{0};


int f(int v, int k){
    if(dp[v][k] != -1) return dp[v][k];
    dp[v][k] = 0;
    if(k == 1){
        return dp[v][k] = g[v].size();
    }
    for(auto& i : g[v]){
        dp[v][k] += f(i, k - 1);
        dp[v][k] %= MOD;
    }
    return dp[v][k];
}

int main() {
	fastio;
    int n, m;
    cin >> n >> m;
    for(int i{0}; i < m; ++i){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i{1}; i <= n; ++i){
        ans += f(i, 7);
        ans %= MOD;
    }
    cout << ans;
}
	

