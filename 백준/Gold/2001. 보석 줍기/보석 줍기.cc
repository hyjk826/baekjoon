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

int dp[101][1 << 14];

int main(){
	fastio;
    int n, m, k;
    cin >> n >> m >> k;
    vi ch(n + 1, -1);
    int cnt{0};
    for(int i{0}; i < k; ++i){
        int a;
        cin >> a;
        ch[a] = cnt++;
    }
    vector<vp> g(n + 1);
    for(int i{0}; i < m; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    queue<pi> Q;
    Q.push({1, 0});
    dp[1][0] = 1;
    while(!Q.empty()){
        int x{Q.front().first};
        int state{Q.front().second};
        Q.pop();
        for(auto& i : g[x]){
            int nx{i.first};            
            if(dp[nx][state] == 0 && __builtin_popcount(state) <= i.second){
                dp[nx][state] = 1;
                Q.push({nx, state});
            }
            if(ch[nx] != -1){
                if(dp[nx][state | (1 << ch[nx])] == 0 && __builtin_popcount(state) <= i.second){
                    dp[nx][state | (1 << ch[nx])] = 1;
                    Q.push({nx, state | (1 << ch[nx])});
                }
            }
        }
    }
    int ans{0};
    for(int i{0}; i < (1 << k); ++i){
        if(dp[1][i]){
            ans = max(ans, __builtin_popcount(i));
        }
    }
    cout << ans;
}
