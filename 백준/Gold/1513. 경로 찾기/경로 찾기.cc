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
#define MOD 1000007
using namespace std;

int dp[51][51][51][51];


int main(){
	fastio;
    memset(dp, -1, sizeof(dp));
    int cnt{1};
    int n, m, k;
    cin >> n >> m >> k;
    vector<vi> board(n, vi(m));
    for(int i{0}; i < k; ++i){
        int a, b;
        cin >> a >> b;
        a--; b--;
        board[a][b] = cnt++;
    }
    function<int(int,int,int,int)> f = [&](int a, int b, int c, int d){
        if(a >= n || b >= m || c < 0) return 0;
        int& ret = dp[a][b][c][d];
        if(ret != -1) return ret;
        ret = 0;
        if(board[a][b]){
            if(board[a][b] <= d) return ret = 0;
            c--; d = board[a][b];
        }
        if(a == n - 1 && b == m - 1){
            if(c == 0) return ret = 1;
        }
        else{
            ret += f(a + 1, b, c, d);
            ret += f(a, b + 1, c, d);
            ret %= MOD;
        }
        return ret;
    };
    for(int i{0}; i <= k; ++i){
        cout << f(0, 0, i, 0) << " ";
    }
}
