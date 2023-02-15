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

int dp[100][10000][101];

int main(){
	fastio;
    int n;
    cin >> n;
    vi vec(n);
    int sum{0};
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
        sum += vec[i];
    }
    memset(dp, -1, sizeof(dp));
    for(int i{0}; i <= n; ++i){
        dp[0][i][i] = abs(vec[0] - i);
    }
    function<int(int,int,int)> f = [&](int a, int b, int c){
        if(b < 0 || c < 0) return (int)1e7;
        if(dp[a][b][c] != -1) return dp[a][b][c];
        if(a == 0) return (int)1e7;
        int mn{MAX};
        for(int i{-1}; i <= 1; ++i){
            mn = min(mn, f(a - 1, b - c, c + i));
        }
        return dp[a][b][c] = abs(vec[a] - c) + mn;
    };
    int ans{MAX};
    for(int i{0}; i <= n; ++i){
        ans = min(ans, f(n - 1, sum, i));
    }
    cout << ans / 2;
}
