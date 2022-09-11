// 2022-09-11
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
    while(t--){
        int n;
        cin >> n;
        vector<vi> board(2, vi(n));
        for(int i{0}; i < 2; ++i){
            for(int j{0}; j < n; ++j){
                cin >> board[i][j];
            }
        }
        vector<vi> dp(2, vi(n));
        dp[0][0] = board[0][0];
        dp[1][0] = board[1][0];
        dp[0][1] = board[0][1] + board[1][0];
        dp[1][1] = board[1][1] + board[0][0];
        for(int j{2}; j < n; ++j){
            for(int i{0}; i < 2; ++i){
                dp[i][j] = max({dp[i ^ 1][j - 1], dp[0][j - 2], dp[1][j - 2]}) + board[i][j];
            }
        }
        cout << max(dp[0][n - 1], dp[1][n - 1]) << "\n";
    }
}