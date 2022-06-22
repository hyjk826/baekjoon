// 2022-06-22
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long
#define MAX 2147000000
#define MOD 1000000000
using namespace std;

int dp[101][10][1024]{};

int main(){
    fastio;
	int n;
    cin >> n;
    for(int i{1}; i < 10; ++i){
        dp[1][i][1 << i] = 1;
    }
    for(int i{2}; i <= n; ++i){
        for(int j{0}; j < 10; ++j){
            for(int k{0}; k < 1024; ++k){
                if(j == 0){
                    dp[i][j][k | (1 << j)] = (dp[i][j][k | (1 << j)] + dp[i - 1][j + 1][k]) % MOD;    
                }
                else if(j == 9){
                    dp[i][j][k | (1 << j)] = (dp[i][j][k | (1 << j)] + dp[i - 1][j - 1][k]) % MOD;    
                }
                else{
                    dp[i][j][k | (1 << j)] = (dp[i][j][k | (1 << j)] + dp[i - 1][j - 1][k]) % MOD;
                    dp[i][j][k | (1 << j)] = (dp[i][j][k | (1 << j)] + dp[i - 1][j + 1][k]) % MOD;
                }
            }
        }
    }
    int ans{0};
    for(int i{0}; i < 10; ++i){
        ans = (ans + dp[n][i][1023]) % MOD;
    }
    cout << ans;
}