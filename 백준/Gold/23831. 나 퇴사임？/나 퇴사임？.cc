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

int dp[101][101][101][2];

int main(){
	fastio;
    int n, A, B;
    cin >> n >> A >> B;
    vector<vi> board(n + 1, vi(4));
    for(int i{1}; i <= n; ++i){
        for(int j{0}; j < 4; ++j){
            cin >> board[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    function<int(int,int,int,int)> f = [&](int a, int b, int c, int d){
        if(a == n + 1) {
            if(c < B) return -MAX;
            else return 0;
        }
        if(dp[a][b][c][d] != -1) return dp[a][b][c][d];
        int& ret = dp[a][b][c][d];
        ret = -MAX;
        if(f(a + 1, b, c + 1, 0) != -MAX) ret = max(ret, f(a + 1, b, c + 1, 0) + board[a][0]);        
        if(f(a + 1, b, c + 1, 0) != -MAX) ret = max(ret, f(a + 1, b, c + 1, 0) + board[a][1]);        
        if(d == 0) {
            if(f(a + 1, b , c, 1) != -MAX) ret = max(ret, f(a + 1, b, c, 1) + board[a][2]);            
        }
        if(b < A) {
            if(f(a + 1, b + 1, c, 0) != -MAX) ret = max(ret, f(a + 1, b + 1, c, 0) + board[a][3]);            
        }
        return ret;
    };
    cout << f(1, 0, 0, 0);
}
