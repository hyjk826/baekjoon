// 2022-05-29
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

vector<pi> graph[100000];
vector<pi> lift[100000];


int main(){
    fastio;
	int n, m, k, s, t;
    cin >> n >> m >> k >> s >> t;
    vector<vl> dp(k + 1, vl(n, -MAX));
    s--;
    t--;
    dp[0][t] = 0;
    for(int i{0}; i < m; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        graph[a].push_back({b, c});
        lift[b].push_back({a, c});
    }
    for(int i{0}; i <= k; ++i){
        for(int j{n - 1}; j >= 0; --j){
            if(i){
                for(auto& u : lift[j]){
                    dp[i][j] = max(dp[i][j], dp[i - 1][u.first]);
                }
            }
            for(auto& u : graph[j]){
                if(dp[i][u.first] == -MAX) continue;
                dp[i][j] = max(dp[i][j], dp[i][u.first] + u.second);
            }
            
        }
    }
    if(dp[k][s] == -MAX) cout << -1;
    else cout << dp[k][s];
}