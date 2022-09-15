// 2022-09-15
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

int n;
vi g[1000001];
vector<vi> dp(1000001, vi(2));

void dfs(int v, int pre){
    dp[v][1]++;
    for(auto& i : g[v]){
        if(i != pre){
            dfs(i, v);
            dp[v][0] += dp[i][1];
            dp[v][1] += min(dp[i][0], dp[i][1]);
        }
    } 
}



int main() {
	fastio;
    cin >> n;
    for(int i{0}; i < n - 1; ++i){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1, -1);
    cout << min(dp[1][0], dp[1][1]);
}
	

