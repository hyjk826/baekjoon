// 2022-11-20
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

vector<vl> dp(31, vl(31, -1));
int xx[]{-1, 0};
int yy[]{0, -1};
int a, b;

ll f(int x, int y){
    if(dp[x][y] != -1) return dp[x][y];
    dp[x][y] = 0;
    for(int dir{0}; dir < 2; ++dir){
        int nx{x + xx[dir]};
        int ny{y + yy[dir]};
        if(nx < a || ny < a || ny > nx) continue;
        dp[x][y] += f(nx, ny);
    }
    return dp[x][y];
}

int main() {
	fastio;
    cin >> a >> b;
    if(a > b) swap(a, b);
    dp[a][a] = 1;
    cout << f(b, b);
}
	

