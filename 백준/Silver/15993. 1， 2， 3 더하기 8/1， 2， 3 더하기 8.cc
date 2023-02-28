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

ll dp[1000001][2];

int main(){
	fastio;
    dp[0][0] = 1;
    for(int i{1}; i <= 1000000; ++i){
        for(int j{1}; j <= 3; ++j){
            if(i >= j){
                dp[i][0] += dp[i - j][1];
                dp[i][1] += dp[i - j][0];
                dp[i][0] %= MOD;
                dp[i][1] %= MOD;
            }
        }
    }
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << dp[n][1] << " " << dp[n][0] << "\n";
    }
}

