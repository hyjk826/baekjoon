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
    int n, k;
    cin >> n >> k;
    vector<vi> board(n, vi(4));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < 4; ++j){
            cin >> board[i][j];
        }
    }
    vector<vi> dp(n, vi(k + 1, -1));
    function<int(int,int)> f = [&](int a, int b){
        if(a == n) return 0;
        if(dp[a][b] != -1) return dp[a][b];
        int& ret = dp[a][b];
        ret = -MAX;
        if(b >= board[a][0]) ret = max(ret, board[a][1] + f(a + 1, b - board[a][0]));
        if(b >= board[a][2]) ret = max(ret, board[a][3] + f(a + 1, b - board[a][2]));
        return ret;
    };
    cout << f(0, k);
}
