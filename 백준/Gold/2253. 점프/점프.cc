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
#define MAX 1000000000
#define MOD 1000000007
using namespace std;

int main(){
	fastio;
    int n, m;
    cin >> n >> m;
    vi ch(n + 1);
    for(int i{0}; i < m; ++i){
        int a;
        cin >> a;
        ch[a] = 1;
    }
    vector<vi> dp(n + 1, vi(500, -1));
    function<int(int,int)> f = [&](int a, int b){
        if(a > n || ch[a]) return MAX;
        if(dp[a][b] != -1) return dp[a][b];
        if(a == n) return dp[a][b] = 0;
        int& ret = dp[a][b];
        ret = MAX;
        for(int i{max(1, b - 1)}; i <= b + 1; ++i){
            ret = min(ret, 1 + f(a + i, i));
        }
        return ret;
    };
    int ans = f(2, 1) + 1;
    if(ans >= MAX) ans = -1;
    cout << ans;
}
