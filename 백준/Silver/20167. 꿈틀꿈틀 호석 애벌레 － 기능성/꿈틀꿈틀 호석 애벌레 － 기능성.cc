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
    int n, k;
    cin >> n >> k;
    vector<vi> dp(n, vi(k, -1));
    vi vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    function<int(int,int)> f = [&](int a, int b){
        if(a >= n) return 0;
        if(dp[a][b] != -1) return dp[a][b];
        int c = b + vec[a];
        dp[a][b] = 0;
        if(c >= k) dp[a][b] = max(dp[a][b], c - k + f(a + 1, 0));
        else dp[a][b] = max(dp[a][b], f(a + 1, c));
        dp[a][b] = max(dp[a][b], f(a + 1, b));
        return dp[a][b];
    };
    cout << f(0, 0);
}
