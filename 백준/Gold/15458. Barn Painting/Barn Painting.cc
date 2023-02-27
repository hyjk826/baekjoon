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
    int n, k;
    cin >> n >> k;
    vector<vi> g(n + 1);
    for(int i{0}; i < n - 1; ++i){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vi ch(n + 1);
    vector<vi> dp(n + 1, vi(4, -1));
    for(int i{0}; i < k; ++i){
        int a, b;
        cin >> a >> b;
        ch[a] = b;
    }
    function<int(int,int, int)> f = [&](int cur, int pre, int color){
        if(dp[cur][color] != -1) return dp[cur][color];
        if(ch[cur] && ch[cur] != color) return 0;
        ll k{1};
        for(auto& i : g[cur]){
            if(i == pre) continue;
            int sum{0};
            for(int j{1}; j <= 3; ++j){
                if(color == j) continue;
                sum += f(i, cur, j);
                sum %= MOD;
            }
            k *= sum;
            k %= MOD;
        }  
        return dp[cur][color] = k;
    };
    int ans{0};
    for(int i{1}; i <= 3; ++i){
        ans += f(1, -1, i);
        ans %= MOD;
    }
    cout << ans;
}
