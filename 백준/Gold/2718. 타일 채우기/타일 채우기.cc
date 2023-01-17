// 2023-01-18
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
    vl dp(101);
    dp[0] = dp[1] = 1;
    dp[2] = 5;
    for(int i{3}; i <= 100; ++i){
        dp[i] += dp[i - 2] * 4;
        dp[i] += dp[i - 1];
        for(int j{3}; j <= i; j += 2){
            dp[i] += dp[i - j] * 2;
        }
        for(int j{4}; j <= i; j += 2){
            dp[i] += dp[i - j] * 3;
        }
    }
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << dp[n] << "\n";
    }
}
