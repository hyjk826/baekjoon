// 2023-01-16
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
    vector<vp> g(n + 1);
    for(int i{0}; i < n - 1; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    ll ans{0};
    function<ll(int, int)> dfs = [&](int cur, int pre){
        ll cnt{1};
        for(auto& i : g[cur]){
            if(i.first == pre) continue;
            ll k = dfs(i.first, cur) * i.second;
            k %= MOD;
            ans += cnt * k;
            ans %= MOD;
            cnt += k;
            cnt %= MOD;
        }
        return cnt;
    };
    dfs(1, 0);
    cout << ans;
}
