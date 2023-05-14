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

int dp[15][1 << 15][10];

int main(){
	fastio;
	int n;
    cin >> n;
    vector<vc> board(n, vc(n));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < n; ++j){
            cin >> board[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    function<int(int,int,int)> f = [&](int a, int b, int c){
        if(dp[a][b][c] != -1) return dp[a][b][c];
        if(b == (1 << n) - 1) return dp[a][b][c] = 1;
        int& ret = dp[a][b][c];
        ret = 1;
        for(int i{0}; i < n; ++i){
            if((b >> i) & 1) continue;
            int k = board[a][i] - '0';
            if(k >= c) ret = max(ret, 1 + f(i, b | (1 << i), k));            
        }
        return ret;
    };
    cout << f(0, 1, 0);
}
