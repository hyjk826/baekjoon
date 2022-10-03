// 2022-10-02
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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vi vec(n);
        for(int i{0}; i < n; ++i) cin >> vec[i];
        int s;
        cin >> s;
        vi dp(s + 1);
        dp[0] = 1;
        for(int i{0}; i < n; ++i){
            for(int j{vec[i]}; j <= s; ++j){
                dp[j] += dp[j - vec[i]];
            }
        }
        cout << dp[s] << "\n";
    }
}
	

