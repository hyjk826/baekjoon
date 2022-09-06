// 2022-09-06
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
    int n, k;
    cin >> n >> k;
    vi dp(k + 1, -MAX);
    dp[0] = 0;
    for(int i{0}; i < n; ++i){
        int a, b;
        cin >> a >> b;
        for(int j{k - a}; j >= 0; --j){
            if(dp[j] == -1) continue;
            dp[j + a] = max(dp[j + a], dp[j] + b);
        }
    }
    int ans{0};
    for(int i{0}; i <= k; ++i){
        ans = max(ans, dp[i]);
    }
    cout << ans;
}
	

