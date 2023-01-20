// 2023-01-21
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
    int n, m;
    cin >> n >> m;
    vector<vi> g(n + 1);
    for(int i{1}; i <= n; ++i){
        int p;
        cin >> p;
        if(i == 1) continue;
        g[p].push_back(i);
    }
    vi ans(n + 1);
    for(int i{0}; i < m; ++i){
        int a, b;
        cin >> a >> b;
        ans[a] += b;
    }
    function<void(int, int)> dfs = [&](int cur, int sum){
        ans[cur] += sum;
        for(auto& i : g[cur]){
            dfs(i, ans[cur]);
        }
    };
    dfs(1, 0);
    for(int i{1}; i <= n; ++i){
        cout << ans[i] << " ";
    }
}
