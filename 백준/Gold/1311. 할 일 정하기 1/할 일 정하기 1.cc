// 2022-12-24
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
    int n;
    cin >> n;
    vector<vi> board(n, vi(n));
    vector<vi> dp(n, vi(1 << n, MAX));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < n; ++j){
            cin >> board[i][j];
        }
    }
    function<int(int, int)> f = [&](int a, int state){
        if(state == (1 << n) - 1) return 0;
        if(dp[a][state] != MAX) return dp[a][state];
        for(int i{0}; i < n; ++i){
            if(state & (1 << i)) continue;
            dp[a][state] = min(dp[a][state], f(a + 1, state | (1 << i)) + board[a][i]);
        }
        return dp[a][state];
    };
    cout << f(0, 0);
}
