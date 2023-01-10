// 2022-08-15
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
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int main() {
	fastio;
    vector<vl> dp(33, vl(33));
    for(int i{0}; i <= 31; ++i){
        dp[0][i] = 1;
    }
    for(int i{1}; i <= 30; ++i){
        for(int j{0}; j <= 30; ++j){
            dp[i][j] += dp[i - 1][j + 1];
            if(j) dp[i][j] += dp[i][j - 1];
        }
    }
    while(1){
        int n;
        cin >> n;
        if(n == 0) break;
        cout << dp[n][0] << "\n";
    }
}

