// 2022-09-14
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
#define MOD 1000000000
using namespace std;

int dp[101][10][1 << 10]{};


int main() {
	fastio;
    int n;
    cin >> n;
    for(int i{1}; i <= 9; ++i){
        dp[1][i][0 | (1 << i)] = 1;
    }
    for(int i{2}; i <= n; ++i){
        for(int j{0}; j <= 9; ++j){
            int a;
            for(int k{0}; k < 2; ++k){
                if(k == 0) a = j - 1;
                else a = j + 1;
                if(a < 0 || a > 9) continue;
                for(int l{0}; l < (1 << 10); ++l){
                    dp[i][j][l | (1 << j)] += dp[i - 1][a][l];
                    dp[i][j][l | (1 << j)] %= MOD;
                }
            }
        }
    }
    int ans{0};
    for(int i{0}; i < 10; ++i){
        ans += dp[n][i][(1 << 10) - 1];
        ans %= MOD;
    }
    cout << ans;
}
	

