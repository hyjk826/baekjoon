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
	int n, k;
    cin >> n >> k;
    vi vec(n);
    for(int i{0}; i < n; ++i) cin >> vec[i];
    vector<vi> dp(n, vi(n, -1));
    function<int(int,int)> f = [&](int l, int r){
        if(dp[l][r] != -1) return dp[l][r];
        if(l == r) return dp[l][r] = 0;
        dp[l][r] = MAX;
        for(int i{l}; i < r; ++i){
            dp[l][r] = min(dp[l][r], f(l, i) + f(i + 1, r) + (vec[l] != vec[i + 1]));
        }
        return dp[l][r];
    };
    cout << f(0, n - 1);
}
