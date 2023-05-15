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
    vp vec(n + 1);
    for(int i{1}; i <= n; ++i){
        cin >> vec[i].first >> vec[i].second;
    }
    sort(vec.begin() + 1, vec.end());
    vi dp(n + 1, MAX);
    dp[0] = 0;
    for(int i{1}; i <= n; ++i){        
        int mx{0};
        for(int j{i}; j >= 1; --j){
            mx = max(mx, abs(vec[j].second * 2));
            dp[i] = min(dp[i], max(vec[i].first - vec[j].first, mx) + dp[j - 1]);
        }   
    }
    cout << dp[n];
}