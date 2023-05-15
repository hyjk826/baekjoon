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
    int n, m, k;
    cin >> n >> m >> k;
    vector<vi> board(n, vi(m));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            cin >> board[i][j];
        }
    }
    vector<vi> dp(n + 1, vi(m + 1));
    dp[0][0] = k - 1;
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            dp[i][j + 1] += dp[i][j] / 2;
            dp[i + 1][j] += dp[i][j] / 2;
            if(dp[i][j] & 1){
                if(board[i][j]) dp[i][j + 1]++;
                else dp[i + 1][j]++;
            }
        }
    }
    int x{0}, y{0};
    while(x < n && y < m){
        if(dp[x][y] & 1){
            if(board[x][y]) x++;
            else y++;
        }
        else{
            if(board[x][y]) y++;
            else x++;
        }
    }
    cout << x + 1 << " " << y + 1;
}