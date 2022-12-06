// 2022-12-04
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


int main() {
	fastio;
	int n, m, k;
    cin >> n >> m >> k;
    vp vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i].first >> vec[i].second;
    }
    vi dp(m + 1, MAX);
    dp[0] = 0;
    for(int i{0}; i < n; ++i){
        for(int j{m}; j >= 0; --j){
            if(dp[j] == MAX) continue;
            for(int l{j + vec[i].second}; l <= m; l += vec[i].second){
                int a = (l - j) / vec[i].second;
                dp[l] = min(dp[l], dp[j] + vec[i].first * a + k * (a - 1) * a / 2);
            }
        }
    }
    cout << dp[m];
}
	
