// 2022-07-29
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

vi graph[10001];
vi vec(10001);
int n;
vector<vi> dp(10001, vi(2));
vi ans;

void dfs(int cur, int pre){
    dp[cur][1] = vec[cur];
    for(auto& i : graph[cur]){
        if(i == pre) continue;
        dfs(i, cur);
        dp[cur][0] += max(dp[i][0], dp[i][1]);
        dp[cur][1] += dp[i][0];
    }
}

void f(int cur, int pre, bool flag){
    if(flag){
        if(dp[cur][1] > dp[cur][0]){
            ans.push_back(cur);
            for(auto& i : graph[cur]){
                if(i == pre) continue;
                f(i, cur, false);
            }
        }
        else{
            for(auto& i : graph[cur]){
                if(i == pre) continue;
                f(i, cur, true);
            }
        }
    }
    else{
        for(auto& i : graph[cur]){
            if(i == pre) continue;
            f(i, cur, true);
        }
    }
}


int main() {
	fastio;    
    cin >> n;
    for(int i{1}; i <= n; ++i){
        cin >> vec[i];
    }
    for(int i{0}; i < n - 1; ++i){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1, -1);
    f(1, -1, true);
    cout << max(dp[1][0], dp[1][1]) << "\n";
    sort(ans.begin(), ans.end());
    for(auto& i : ans) cout << i << " ";
}

