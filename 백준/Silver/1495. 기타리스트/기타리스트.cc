// 2022-07-25
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
    int n, s, m;
    cin >> n >> s >> m;
    vector<vi> dp(n + 1, vi(m + 1));
    dp[0][s] = 1; 
    vi vec(n);
    for(int i{0}; i < n; ++i) cin >> vec[i];
    for(int i{0}; i <= n - 1; ++i){
        for(int j{0}; j <= m; ++j){
            if(dp[i][j]){
                int k = j + vec[i];
                if(0 <= k && k <= m) dp[i + 1][k] = 1;
                k = j - vec[i];
                if(0 <= k && k <= m) dp[i + 1][k] = 1;
            }
        }
    }
    int mx{-1};
    for(int i{0}; i <= m; ++i){
        if(dp[n][i]) mx = i;
    }
    cout << mx;
}

