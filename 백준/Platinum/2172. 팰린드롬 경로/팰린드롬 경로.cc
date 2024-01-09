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
#define MAX 2147000000
#define MOD 1000000007
typedef long long ll;
using namespace std;

int dp[400][400][21];

void solve(){
    int n, L;
    cin >> n >> L;
    vector<vi> board(n, vi(n));
    vector<vi> g(10);
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < n; ++j){
            cin >> board[i][j];
            g[board[i][j]].push_back(i * n + j);
        }
    }
    if(L == 1){
        cout << n * n << "\n"; return;
    }
    memset(dp, -1, sizeof(dp));
    int xx[]{-1,-1,-1,0,0,1,1,1};
    int yy[]{-1,0,1,-1,1,-1,0,1};
    function<int(int,int,int)> f = [&](int a, int b, int c){
        if(c == 0) return 1;
        if(dp[a][b][c] != -1) return dp[a][b][c];
        int x1 = a / n; int y1 = a % n;
        int x2 = b / n; int y2 = b % n;
        int& ret = dp[a][b][c];
        ret = 0;
        for(int d1{0}; d1 < 8; ++d1){
            for(int d2{0}; d2 < 8; ++d2){
                int nx1 = x1 + xx[d1]; int ny1 = y1 + yy[d1];
                int nx2 = x2 + xx[d2]; int ny2 = y2 + yy[d2];
                if(nx1 < 0 || nx1 > n - 1 || ny1 < 0 || ny1 > n - 1) continue;
                if(nx2 < 0 || nx2 > n - 1 || ny2 < 0 || ny2 > n - 1) continue;
                if(board[nx1][ny1] ^ board[nx2][ny2]) continue;
                ret += f(nx1 * n + ny1, nx2 * n + ny2, c - 2);
            }
        }
        return ret;
    };
    int ans{0};
    if(L & 1){
        for(int i{0}; i < n; ++i){
            for(int j{0}; j < n; ++j){
                ans += f(i * n + j, i * n + j, L - 1);
            }
        }
    }
    else{
        for(int i{0}; i <= 9; ++i){
            auto& v = g[i];
            for(int j{0}; j < (int)v.size(); ++j){
                for(int k{0}; k < (int)v.size(); ++k){
                    if(j == k) continue;
                    int x1 = v[j] / n; int y1 = v[j] % n;
                    int x2 = v[k] / n; int y2 = v[k] % n;
                    if(abs(x1 - x2) > 1 || abs(y1 - y2) > 1) continue;
                    ans += f(v[j], v[k], L - 2);
                }
            }
        }
    }
    cout << ans << "\n";
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
