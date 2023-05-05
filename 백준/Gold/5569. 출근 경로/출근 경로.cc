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
#define MOD 100000
using namespace std;

int dp[100][100][2][2];

int main(){
	fastio;
    memset(dp, -1, sizeof(dp));
    int n, m;
    cin >> n >> m;
    int xx[]{0, 1};
    int yy[]{1, 0};
    function<int(int,int,int,int)> f = [&](int a, int b, int c, int d){
        if(dp[a][b][c][d] != -1) return dp[a][b][c][d];
        if(a == n - 1 && b == m - 1) return dp[a][b][c][d] = 1;
        int& ret = dp[a][b][c][d];
        ret = 0;
        for(int dir{0}; dir < 2; ++dir){
            int nx{a + xx[dir]};
            int ny{b + yy[dir]};
            if(nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1) continue;
            if(dir == d) ret += f(nx, ny, 0, dir);
            else if(c == 0) ret += f(nx, ny, 1, dir);
            ret %= MOD;
        }
        return ret;
    };
    int ans{0};
    ans += f(0, 1, 0, 0);
    ans += f(1, 0, 0, 1);
    ans %= MOD;
    cout << ans;
}
