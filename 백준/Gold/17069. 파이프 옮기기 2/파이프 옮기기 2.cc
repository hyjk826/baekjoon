// 2023-01-17
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
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < n; ++j){
            cin >> board[i][j];
        }
    }
    ll dp[32][32][3];
    memset(dp, -1, sizeof(dp));
    dp[0][1][0] = 1;
    int xx[]{0,-1, -1};
    int yy[]{-1, -1, 0};
    function<ll(int, int, int)> f = [&](int x, int y, int dir){
        if(dp[x][y][dir] != -1) return dp[x][y][dir];
        if(board[x][y] == 1) return dp[x][y][dir] = 0;
        ll& ret = dp[x][y][dir];
        ret = 0;
        int nx = x + xx[dir];
        int ny = y + yy[dir];
        if(nx < 0 || nx > n - 1 || ny < 0 || ny > n - 1 || board[nx][ny]) return ret = 0;
        if(dir == 0){
            return ret = f(nx, ny, 0) + f(nx, ny, 1);
        }
        else if(dir == 1){
            if(board[nx + 1][ny] || board[nx][ny + 1]) return ret = 0;
            return ret = f(nx, ny, 0) + f(nx, ny, 1) + f(nx, ny, 2);
        }
        else{
            return ret = f(nx, ny, 1) + f(nx, ny, 2);
        }
    };
    ll ans{0};
    for(int i{0}; i < 3; ++i){
        ans += f(n - 1, n - 1, i);
    }
    cout << ans;
}
