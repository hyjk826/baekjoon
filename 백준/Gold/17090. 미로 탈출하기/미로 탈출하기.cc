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

int dp[500][500];

int main(){
	fastio;
    int n, m;
    cin >> n >> m;
    vector<vc> board(n, vc(m));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            cin >> board[i][j];
        }
    }
    int xx[]{-1,0,1,0};
    int yy[]{0,1,0,-1};
    string dd = "URDL";
    memset(dp, -1, sizeof(dp));
    vector<vi> ch(n, vi(m));
    function<int(int,int)> f = [&](int a, int b){
        if(dp[a][b] != -1) return dp[a][b];
        int dir = dd.find(board[a][b]);
        int nx = a + xx[dir];
        int ny = b + yy[dir];
        if(nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1) return dp[a][b] = 1;
        if(ch[nx][ny]) return dp[a][b] = 0;
        else{
            ch[nx][ny] = 1;
            dp[a][b] = f(nx, ny);
            ch[nx][ny] = 0;
            return dp[a][b];
        }
    };
    int ans{0};
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            ch[i][j] = 1;
            ans += f(i, j);
            ch[i][j] = 0;
        }
    }
    cout << ans;
}
