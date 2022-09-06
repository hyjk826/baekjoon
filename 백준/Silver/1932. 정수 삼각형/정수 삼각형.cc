// 2022-09-06
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
    int n;
    cin >> n;
    vector<vi> board(n, vi(n));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < i + 1; ++j){
            cin >> board[i][j];
        }
    }
    vector<vi> dp(n, vi(n));
    dp[0][0] = board[0][0];
    for(int i{1}; i < n; ++i){
        for(int j{0}; j < i + 1; ++j){
            if(j == 0){
                dp[i][j] = dp[i - 1][0] + board[i][j];
            }
            else if(j == i){
                dp[i][j] = dp[i - 1][j - 1] + board[i][j];
            }
            else{
                dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + board[i][j];
            }
        }
    }
    int ans{0};
    for(int i{0}; i < n; ++i){
        ans = max(ans, dp[n - 1][i]);
    }
    cout << ans;
}
	

