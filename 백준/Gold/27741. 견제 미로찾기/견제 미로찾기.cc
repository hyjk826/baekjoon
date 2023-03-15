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

int dp[300][300][300];

int main(){
	fastio;
    int n, k;
    cin >> n >> k;
    vector<vi> board(n, vi(n));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < n; ++j){
            cin >> board[i][j];
        }
    }
    vector<vi> div(k + 1);
    for(int i{1}; i <= k; ++i){
        for(int j{i * 2}; j <= k; j += i){
            div[j].push_back(i);
        }
    }
    memset(dp, -1, sizeof(dp));
    dp[n - 1][n - 1][1] = 0;
    function<int(int,int,int)> f = [&](int a, int b, int c){
        if(dp[a][b][c] != -1) return dp[a][b][c];
        bool ok = false;
        for(int j{1}; j <= c; ++j){
            if(b + j > n - 1 || board[a][b + j] == 1) break;
            if(f(a, b + j, c) == 0) ok = 1;
        }
        for(int i{1}; i <= c; ++i){
            if(a + i > n - 1 || board[a + i][b] == 1) break;
            if(f(a + i, b, c) == 0) ok = 1;
        }
        for(auto& i : div[c]){
            if(f(a, b, i) == 0) ok = 1;
        }
        if(ok) return dp[a][b][c] = 1;
        else return dp[a][b][c] = 0;
    };
    if(f(0, 0, k)) cout << 1;
    else cout << 0;
}
