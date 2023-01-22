// 2023-01-22
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
#define MOD 10000003
using namespace std;

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main(){
	fastio;
    int n;
    cin >> n;
    vi vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    vector<vi> dp(n + 1, vi(100001));
    dp[0][0] = 1;
    for(int i{0}; i < n; ++i){
        dp[i + 1] = dp[i];
        for(int j{0}; j <= 100000; ++j){
            if(dp[i][j] == 0) continue;
            int k = gcd(j, vec[i]);
            dp[i + 1][k] += dp[i][j];
            dp[i + 1][k] %= MOD;
        }
    }
    cout << dp[n][1];
}
