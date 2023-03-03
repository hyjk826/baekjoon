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

int dp[100][100][80];

int main(){
	fastio;
    int n, m, k;
    cin >> n >> m >> k;
    vector<vc> board(n, vc(m));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            cin >> board[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    string str;
    cin >> str;
    int ans{0};
    int xx[]{-1,0,1,0};
    int yy[]{0,1,0,-1};
    function<int(int,int,int)> f = [&](int a, int b, int c){
        if(dp[a][b][c] != -1) return dp[a][b][c];
        if(c == (int)str.size() - 1) {
            if(board[a][b] == str[c]) return dp[a][b][c] = 1;
            else return dp[a][b][c] = 0;
        }
        if(board[a][b] != str[c]) return dp[a][b][c] = 0;
        int& ret = dp[a][b][c];
        ret = 0;
        for(int dir{0}; dir < 4; ++dir){
            int x = a; 
            int y = b;
            for(int j{0}; j < k; ++j){
                x += xx[dir];
                y += yy[dir];
                if(x < 0 || x > n - 1 || y < 0 || y > m - 1) break;
                ret += f(x, y, c + 1);
            }
        }
        return ret;
    };
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            ans += f(i, j, 0);
        }
    }
    cout << ans;
}
