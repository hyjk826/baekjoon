// 2023-01-20
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
#define MAX 1000000000
#define MOD 1000000007
using namespace std;

int main(){
	fastio; 
    int n, k;
    cin >> n >> k;
    vi vec(n + 1);
    for(int i{1}; i <= n; ++i){
        cin >> vec[i];
    }
    vi preSum = vec;
    for(int i{1}; i <= n; ++i){
        preSum[i] += preSum[i - 1];
    }
    vector<vi> dp(n + 1, vi(n + 1, -1));
    function<int(int,int)> f = [&](int a, int b){
        if(b == 0) return 0;        
        if(a > n) return -MAX;
        if(dp[a][b] != -1) return dp[a][b];
        if((n - a + 2) / 2 < b) return dp[a][b] = -MAX;
        dp[a][b] = -MAX;
        for(int i{a}; i <= n; ++i){
            dp[a][b] = max(dp[a][b], preSum[i] - preSum[a - 1] + f(i + 2, b - 1));
        }
        dp[a][b] = max(dp[a][b], f(a + 1, b));
        return dp[a][b];
    };
    cout << f(1, k);
}
