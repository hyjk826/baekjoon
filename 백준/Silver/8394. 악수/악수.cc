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
    int n;
    cin >> n;
    vi A = {1,1,2,3,5,8,3,1,4,5,9,4,3,7,0};
    vi dp(n + 1);
    dp[0] = dp[1] = 1;
    for(int i{2}; i <= n; ++i){
        dp[i] = (dp[i - 1] + dp[i - 2]) % 10;
    }
    cout << dp.back();
}
