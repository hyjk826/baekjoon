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

struct st{
    int a, x, y, c;
};

int dp[5001][101];

int main(){
	fastio;
    int n, m, t;
    cin >> n >> m >> t;
    vector<st> vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i].a >> vec[i].x >> vec[i].y >> vec[i].c;
    }
    vector<vi> g(n);
    for(int i{0}; i < m; ++i){
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
    }
    memset(dp, -1, sizeof(dp));
    ll def = (ll)1e10;
    function<int(int,int)> f = [&](int a, int b){
        if(dp[a][b] != -1) return dp[a][b];
        dp[a][b] = 0;
        if(b == t || vec[a].a + vec[a].x * b - vec[a].y * def > 0) return dp[a][b];
        dp[a][b] = vec[a].c;
        int mx{0};
        for(auto& i : g[a]){
            mx = max(mx, f(i, b + 1));
        }
        dp[a][b] += mx;
        return dp[a][b];
    };
    int mx = f(0, 0);
    ll l{0}, r{(ll)1e10};
    ll ans{0};
    while(l <= r){
        ll mid{(l + r) >> 1};
        memset(dp, -1, sizeof(dp));
        def = mid;
        if(f(0, 0) == mx){
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << ans;
}
