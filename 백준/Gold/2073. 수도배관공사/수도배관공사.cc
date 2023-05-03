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
	int D, n;
    cin >> D >> n;
    vi dp(D + 1, -1);
    dp[0] = MAX;
    for(int i{0}; i < n; ++i){
        int a, b;
        cin >> a >> b;
        for(int j{D}; j >= a; --j){
            if(dp[j - a] == -1) continue;
            dp[j] = max(dp[j], min(dp[j - a], b));
        }
    }
    cout << dp[D];
}
