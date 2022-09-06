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
    vector<vi> board(n, vi(3));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < 3; ++j){
            cin >> board[i][j];
        }
    }
    vector<vi> dp(n, vi(3, MAX));
    for(int i{0}; i < 3; ++i){
        dp[0][i] = board[0][i];
    }
    for(int i{1}; i < n; ++i){
        for(int j{0}; j < 3; ++j){
            for(int k{0}; k < 3; ++k){
                if(j == k) continue;
                dp[i][j] = min(dp[i][j], dp[i - 1][k] + board[i][j]);
            }
        }
    }
    cout << min({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});
}
	

