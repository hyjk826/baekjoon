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
	int t;
    t = 1;
    while(t--){
        int n;
        cin >> n;
        vp vec(n);
        int sum{0};
        for(int i{0}; i < n; ++i){
            cin >> vec[i].first >> vec[i].second;
            sum += vec[i].first;
        }
        vi dp(sum + 1, MAX);
        dp[0] = 0;
        for(int i{0}; i < n; ++i){
            for(int j{sum}; j >= vec[i].first; --j){
                if(dp[j - vec[i].first] == MAX) continue;
                dp[j] = min(dp[j], dp[j - vec[i].first] + vec[i].second);
            }
        }
        int ans{MAX};
        for(int i{0}; i <= sum; ++i){
            ans = min(ans, max(sum - i,dp[i]));
        }
        cout << ans << "\n";
    }
}
