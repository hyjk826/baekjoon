// 2022-11-13
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

vi dp;

int f(int n, vector<vi>& g){
    if(dp[n] != -1) return dp[n];
    dp[n] = 1;
    for(auto& i : g[n]){
        dp[n] = max(dp[n], f(i, g) + 1);
    }
    return dp[n];
}


int main() {
	fastio;
    int n, m;
    cin >> n >> m;
    vp edge;
    vi degree(n);
    dp.resize(n, -1);
    for(int i{0}; i < m; ++i){
        int a, b;
        cin >> a >> b;
        edge.push_back({a, b});
        degree[a]++;
        degree[b]++;
    }
    vector<vi> g(n);
    for(int i{0}; i < m; ++i){
        int a = edge[i].first;
        int b = edge[i].second;
        if(degree[a] == degree[b]) continue;
        if(degree[a] > degree[b]) g[a].push_back(b);
        else g[b].push_back(a);
    }
    int ans{1};
    for(int i{0}; i < n; ++i){
        ans = max(ans, f(i, g));
    }
    cout << ans;
}
	

