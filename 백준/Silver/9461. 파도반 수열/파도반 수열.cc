// 2022-09-10
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define vs vector<string>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int main(){
    fastio;
    vl dp(101);
    dp[0] = dp[1] = dp[2] = 1;
    dp[3] = dp[4] = 2;
    for(int i{5}; i <= 100; ++i){
        dp[i] = dp[i - 1] + dp[i - 5];
    }
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << dp[n - 1] << "\n";
    }
}