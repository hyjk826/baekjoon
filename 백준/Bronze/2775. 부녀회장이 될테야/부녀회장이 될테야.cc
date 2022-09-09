// 2022-09-09
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define vs vector<string>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int main(){
    fastio;
    int t;
    cin >> t;
    vector<vi> dp(15, vi(15));
    for(int i{1}; i <= 14; ++i){
        dp[0][i] = i;
    }
    for(int i{1}; i <= 14; ++i){
        for(int j{1}; j <= 14; ++j){
            for(int a{1}; a <= j; ++a){
                dp[i][j] += dp[i - 1][a];
            }
        }
    }
    while(t--){
        int n, k;
        cin >> n >> k;        
        cout << dp[n][k] << "\n";
    }
}