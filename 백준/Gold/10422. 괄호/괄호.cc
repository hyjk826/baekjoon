// 2022-12-12
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

int main() {
	fastio;
    vl dp(5001);
    dp[0] = dp[2] = 1;
    for(int i{4}; i <= 5000; ++i){
        for(int j{i - 1}; j >= 1; j -= 2){
            dp[i] += 1LL * dp[j - 1] * dp[i - j - 1]; 
            dp[i] %= MOD;
        }
    }
	int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << dp[n] << '\n';
    }
}
	
