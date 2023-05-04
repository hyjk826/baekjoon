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
#define MOD 1000000009
using namespace std;

ll dp[100001];

int main(){
	fastio;
    dp[1] = dp[0] = 1;
    for(int i{2}; i <= 100000; ++i){
        if(i == 2 || i == 3) dp[i]++;
        dp[i] += dp[i - 2];
        dp[i] %= MOD;
        if(i - 4 >= 0){ 
            dp[i] += dp[i - 4];
            dp[i] %= MOD;
        }
        if(i - 6 >= 0) {
            dp[i] += dp[i - 6];
            dp[i] %= MOD;
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
