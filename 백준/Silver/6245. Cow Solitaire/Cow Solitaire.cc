// 2022-11-16
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

int dp[7][7];
int xx[]{1,0};
int yy[]{0,-1};


int f(int x, int y, int n, vector<vi>& board){
    if(dp[x][y] != -1) return dp[x][y];
    int mx{0};
    for(int dir{0}; dir < 2; ++dir){
        int nx{x + xx[dir]};
        int ny{y + yy[dir]};
        if(nx < 0 || nx > n - 1 || ny < 0 || ny > n - 1) continue;
        mx = max(mx, f(nx, ny, n, board));
    }
    return dp[x][y] = mx + board[x][y];
}

int main() {
	fastio;
    int n;
    cin >> n;
    vector<vi> board(n, vi(n));
    string str = "A23456789TJQK";
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < n; ++j){
            string s;
            cin >> s;
            int idx = find(str.begin(), str.end(), s[0]) - str.begin();
            board[i][j] = idx + 1;
        }
    }
    memset(dp, -1, sizeof(dp));
    cout << f(0, n - 1, n, board);
}
	

