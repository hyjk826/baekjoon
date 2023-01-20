// 2023-01-20
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
    vector<vi> dp(n + 1, vi(n + 1, -1));
    vi ch(n + 1);
    for(int i{0}; i < m; ++i){
        int a;
        cin >> a;
        ch[a] = 1;
    }
    function<int(int, int)> f = [&](int a, int b){
        if(a > n) return 0;
        if(dp[a][b] != -1) return dp[a][b];
        if(ch[a]) return dp[a][b] = f(a + 1, b);
        int& ret = dp[a][b];
        ret = MAX;
        if(b >= 3) ret = min(ret, f(a + 1, b - 3));
        ret = min(ret, f(a + 5, b + 2) + 37000);
        ret = min(ret, f(a + 3, b + 1) + 25000);
        ret = min(ret, f(a + 1, b) + 10000);
        return ret;
    };
    cout << f(1, 0);
}
