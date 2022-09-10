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
    vi dp(1001);
    dp[0] = dp[1] = 1;
    for(int i{2}; i <= 1000; ++i){
        dp[i] = dp[i - 1] + dp[i - 2] * 2;
        dp[i] %= 10007;
    }
    int n;
    cin >> n;
    cout << dp[n];
}