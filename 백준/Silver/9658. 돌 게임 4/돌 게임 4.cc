// 2022-08-31
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
    int n;
    cin >> n;
    vi dp(n + 1);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 1;
    dp[4] = 2;
    for(int i{5}; i <= n; ++i){
        bool flag = true;
        flag &= (dp[i - 1] == 2);
        flag &= (dp[i - 3] == 2);
        flag &= (dp[i - 4] == 2);
        if(flag) dp[i] = 1;
        else dp[i] = 2;
    } 
    if(dp[n] == 2) cout << "SK";
    else cout << "CY";
}

