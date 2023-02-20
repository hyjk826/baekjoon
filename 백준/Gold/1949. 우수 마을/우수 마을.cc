// 2022-03-04
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<ll>
#define vc vector<char>
#define vp vector<pair<int, int> >
#define pi pair<int, int>
#define sz(v) int(v.size())
#define all(v) v.begin(), v.end()
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

vi graph[10001];
vi population(10001);
int dp[10001][2]{};
int n;

void dfs(int v, int pre){
    dp[v][1] = population[v];
    int a{0}, b{0};
    for(int i{0}; i < (int)graph[v].size(); ++i){
        int nv = graph[v][i];
        if(nv == pre) continue;
        dfs(nv, v);
        dp[v][0] += max(dp[nv][0], dp[nv][1]);
        dp[v][1] += dp[nv][0];
    }
}

int main(){
    fastio;
    cin >> n;
    for(int i{1}; i <= n; ++i){
        cin >> population[i];
    }
    for(int i{0}; i < n - 1; ++i){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1, -1);
    cout << max(dp[1][0], dp[1][1]);
}