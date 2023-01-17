// 2023-01-18
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
    int c, n;
    cin >> c >> n;
    vp vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i].first >> vec[i].second;
    }
    vi dp(c + 1, MAX);
    dp[0] = 0;
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < c; ++j){
            if(dp[j] == MAX) continue;
            int k = min(c, j + vec[i].second);
            dp[k] = min(dp[k], dp[j] + vec[i].first);
        }
    }
    cout << dp[c];
}
