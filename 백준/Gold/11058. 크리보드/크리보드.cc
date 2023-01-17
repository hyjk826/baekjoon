// 2023-01-17
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
    int n;
    cin >> n;
    vl dp(n + 1);
    for(int i{1}; i <= n; ++i){
        dp[i] = dp[i - 1] + 1;
        for(int j{3}; j < i; ++j){
            dp[i] = max(dp[i], dp[i - j] * (j - 1));
        }
    }
    cout << dp[n];
}
