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
    for(int i{0}; i < n - 1; ++i){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vi sub(n + 1);
    function<void(int,int)> dfs = [&](int cur, int pre){
        sub[cur] = 1;
        for(auto& i : g[cur]){
            if(i == pre) continue;
            dfs(i, cur);
            sub[cur] += sub[i];
        }
    };
    dfs(1, -1);
    ll ans{0};
    for(int i{2}; i <= n; ++i){
        int a = sub[i];
        int b = n - sub[i];
        ans += 1LL * a * (a - 1) / 2;
        ans += a * b;
    }
    cout << ans;
}
