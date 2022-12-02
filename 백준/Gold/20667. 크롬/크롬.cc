// 2022-12-02
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

int dp[1001][501];

int main() {
	fastio;
	int n, m, k;
    cin >> n >> m >> k;
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    for(int i{0}; i < n; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        for(int j{1000}; j >= 0; --j){
            for(int k{500}; k >= 0; --k){
                if(dp[j][k] == -1) continue;
                dp[min(j + a, 1000)][min(k + c, 500)] = max(dp[min(j + a, 1000)][min(k + c, 500)], dp[j][k] + b);
            }
        }
    }
    int ans{MAX};
    for(int i{m}; i <= 1000; ++i){
        for(int j{1}; j <= 500; ++j){
            if(dp[i][j] == -1) continue;
            if(dp[i][j] >= k){
                ans = min(ans, j);
            }
        }
    }
    if(ans == MAX) cout << -1;
    else cout << ans;
}
	
