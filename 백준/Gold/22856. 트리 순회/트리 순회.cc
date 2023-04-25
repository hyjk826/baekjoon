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
    for(int i{1}; i <= n; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back(b);
        g[a].push_back(c);
    }
    int k{-1};
    function<void(int)> f = [&](int cur){
        if(g[cur][0] != -1) f(g[cur][0]);
        k = cur;
        if(g[cur][1] != -1) f(g[cur][1]);
    };
    f(1);
    int ans{0};
    int cnt{0};
    function<void(int)> dfs = [&](int cur){
        cnt++;        
        for(auto& i : g[cur]){
            if(i == -1) continue;
            ans++;
            dfs(i);
            ans++;
        }
        if(k == cur){
            cout << ans; exit(0);
        }
    };
    dfs(1);
}
