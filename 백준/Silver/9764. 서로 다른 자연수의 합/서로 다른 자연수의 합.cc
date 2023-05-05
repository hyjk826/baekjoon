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
    vi dp(2001);
    dp[0] = 1;
    for(int i{1}; i <= 2000; ++i){
        for(int j{2000}; j >= i; --j){
            dp[j] += dp[j - i];
            dp[j] %= 100999;
        }
    }
    int q;
    cin >> q;
    while(q--){
        int n;
        cin >> n;
        cout << dp[n] << "\n";
    }
}
