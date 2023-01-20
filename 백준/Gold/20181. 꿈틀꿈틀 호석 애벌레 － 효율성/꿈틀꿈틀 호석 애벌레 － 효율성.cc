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
    vl dp(n + 1, -1);
    vl vec(n + 1);
    for(int i{1}; i <= n; ++i){
        cin >> vec[i];
    }
    vl preSum = vec;
    for(int i{1}; i <= n; ++i){
        preSum[i] += preSum[i - 1];
    }
    function<ll(int)> f = [&](int a){
        if(a > n) return 0LL;
        if(dp[a] != -1) return dp[a];
        dp[a] = 0;
        dp[a] = max(dp[a], f(a + 1));
        auto it = lower_bound(preSum.begin(), preSum.end(), preSum[a - 1] + k);
        if(it != preSum.end()){
            dp[a] = max(dp[a], *it - preSum[a - 1] - k + f(it - preSum.begin() + 1));
        }
        return dp[a];
    };
    cout << f(1);
}
