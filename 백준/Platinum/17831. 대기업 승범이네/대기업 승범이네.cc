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

int main(){
	fastio;
    int n;
    cin >> n;
    vector<vi> g(n + 1);
    for(int i{2}; i <= n; ++i){
        int p;
        cin >> p;
        g[p].push_back(i);
    }
    vector<vl> dp(n + 1, vl(2));
    vi A(n + 1);
    for(int i{1}; i <= n; ++i){
        cin >> A[i];
    }
    function<void(int)> dfs = [&](int cur){
        ll sum{0};
        for(auto& i : g[cur]){
            dfs(i);
            sum += max(dp[i][0], dp[i][1]);
        }
        dp[cur][0] = sum;
        for(auto& i : g[cur]){
            dp[cur][1] = max(dp[cur][1], A[cur] * A[i] + dp[i][0] + (sum - max(dp[i][0], dp[i][1])));
        }
    };
    dfs(1);
    cout << max(dp[1][0], dp[1][1]);
}
