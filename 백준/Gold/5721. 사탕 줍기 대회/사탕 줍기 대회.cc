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

void solve(int n, int m){
    vector<vi> board(n, vi(m));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            cin >> board[i][j];
        }
    }
    vector<vi> dp(n, vi(m, -1));
    function<int(int,int)> f = [&](int x, int y){
        if(dp[x][y] != -1) return dp[x][y];
        int& ret = dp[x][y];
        ret = board[x][y];
        if(y == 0 && x + 1 < n) ret = max(ret, f(x + 1, 0));
        if(y + 1 < m) ret = max(ret, f(x, y + 1));
        if(x + 2 < n) ret = max(ret, board[x][y] + f(x + 2, 0));
        if(y + 2 < m) ret = max(ret, f(x, y + 2) + board[x][y]);
        return ret;
    };
    cout << f(0, 0) << "\n";
}

int main(){
	fastio;
	while(1){
        int n, m;
        cin >> n >> m;
        if(n == 0 && m == 0) break;
		solve(n, m);
	}
}
