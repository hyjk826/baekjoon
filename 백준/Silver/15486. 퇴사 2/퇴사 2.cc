// 2022-07-31
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

vp vec(1500001);
vl dp(1500002, -1);
int n;

ll f(int k){
    if(dp[k] != -1) return dp[k];
    dp[k] = 0;
    if(vec[k].first + k <= n + 1){
        dp[k] = vec[k].second + f(k + vec[k].first);
    }
    if(k + 1 <= n) dp[k] = max(dp[k], f(k + 1));
    return dp[k];
}

int main() {
	fastio;
    cin >> n;
    for(int i{1}; i <= n; ++i){
        cin >> vec[i].first >> vec[i].second;
    }    
    cout << f(1);
}

