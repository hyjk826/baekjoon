// 2022-07-25
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
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

vector<vi> dp(16, vi(1 << 16, -1));
int dis[16][16];
int n;

int f(int a, int b){
    if(dp[a][b] != -1) return dp[a][b];
    if(b == (1 << n) - 1){
        if(dis[a][0] != 0) return dp[a][b] = dis[a][0];
        return dp[a][b] = 1e9;
    }
    int r = 1e9;
    for(int i{0}; i < n; ++i){
        if(b & (1 << i) || dis[a][i] == 0) continue;
        r = min(r, f(i, b | (1 << i)) + dis[a][i]);
    }
    return dp[a][b] = r;
}

int main() {
	fastio;
    cin >> n;
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < n; ++j){
            cin >> dis[i][j];
        }
    }
    cout << f(0, 1);
}

