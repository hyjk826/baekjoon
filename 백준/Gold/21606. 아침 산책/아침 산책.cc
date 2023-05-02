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
    string str;
    cin >> str;
    vector<vi> g(n + 1);
    for(int i{0}; i < n - 1; ++i){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vi dp(n + 1);
    ll ans{0};
    function<void(int,int)> f = [&](int cur, int pre){
        if(str[cur - 1] == '1') dp[cur] = 1;
        int sum{0};
        for(auto& i : g[cur]){
            if(i == pre) continue;
            f(i, cur);
            if(str[cur - 1] == '1') ans += dp[i];
            else {
                ans += 1LL * dp[i] * dp[cur];
                dp[cur] += dp[i];
            }
        }
    };
    f(1, -1);
    cout << ans * 2;
}
