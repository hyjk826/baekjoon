// 2022-08-18
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

vector<vi> dp(3001, vi(2, MAX));
int n;

int f(int a, int k, vi& preSum){
    if(a > n) return 0;
    if(dp[a][k] != MAX) return dp[a][k];
    dp[a][k] = 0;
    if(k == 0){
        int mn{MAX};
        for(int i{a}; i <= n; ++i){
            mn = min(mn, preSum[i] - preSum[a - 1] + f(i + 1, 1, preSum));
        }
        dp[a][k] += mn;
    }
    else{
        int mx{-MAX};
        for(int i{a}; i <= n; ++i){
            mx = max(mx, -(preSum[i] - preSum[a - 1]) + f(i + 1, 0,preSum));
        }
        dp[a][k] += mx;
    }
    return dp[a][k];
}

int main() {
	fastio;
    cin >> n;
    for(int t{0}; t < 3; ++t){
        for(int i{0}; i <= n; ++i){
            for(int j{0}; j < 2; ++j){
                dp[i][j] = MAX;
            }
        }
        vi vec(n + 1);
        for(int i{n}; i >= 1; --i){
            cin >> vec[i];
        }
        vi preSum = vec;
        for(int i{1}; i <= n; ++i){
            preSum[i] += preSum[i - 1];
        }
        int k = f(1, 0, preSum);
        if(k < 0) cout << "A\n";
        else if(k > 0) cout << "B\n";
        else cout << "D\n";
    }
}