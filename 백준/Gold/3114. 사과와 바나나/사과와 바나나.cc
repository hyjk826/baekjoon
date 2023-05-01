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
    int n, m;
    cin >> n >> m;
    vector<vi> A(n + 2, vi(m + 2)), B(n + 2, vi(m + 2));
    for(int i{1}; i <= n; ++i){
        for(int j{1}; j <= m; ++j){
            string str;
            cin >> str;
            if(str[0] == 'A') A[i][j] = stoi(str.substr(1));
            else B[i][j] = stoi(str.substr(1));
        }
    }
    for(int j{1}; j <= m; ++j){
        for(int i{1}; i <= n; ++i){
            B[i][j] += B[i - 1][j];
        }
    }
    for(int j{1}; j <= m; ++j){
        for(int i{n}; i >= 0; --i){
            A[i][j] += A[i + 1][j];
        }
    }
    vector<vi> dp(n + 1, vi(m + 1));
    dp[1][1] = A[2][1];
    for(int i{1}; i <= n; ++i){
        for(int j{1}; j <= m; ++j){
            if(i - 1 >= 1 && j - 1 >= 1) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + B[i - 1][j] + A[i + 1][j]);            
            if(j - 1 >= 1) dp[i][j] = max(dp[i][j], dp[i][j - 1] + B[i - 1][j] + A[i + 1][j]);
            if(i - 1 >= 1) dp[i][j] = max(dp[i][j], dp[i - 1][j] - (A[i][j] - A[i + 1][j]));            
        }
    }
    cout << dp[n][m];
}
