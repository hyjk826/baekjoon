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

int dp[101][101][101];

void solve(){
	int n, m, a, b;
    cin >> n >> m >> a >> b;
    vector<vi> A(n + 1, vi(m + 1));
    vector<vi> B(n + 1, vi(m + 1));
    for(int i{0}; i < a; ++i){
        int a, b;
        cin >> a >> b;
        A[a][b] = 1;
    }
    for(int i{0}; i < b; ++i){
        int a, b;
        cin >> a >> b;
        B[a][b] = 1;
    }
    memset(dp, -1, sizeof(dp));
    int xx[]{0, 1};
    int yy[]{1, 0};
    function<int(int,int,int)> f = [&](int x, int y, int c){
        if(x == n && y == m) {
            if(c == a) return 1;
            else return 0;
        }
        else{
            if(dp[x][y][c] != -1) return dp[x][y][c];
            int& ret = dp[x][y][c];
            ret = 0;
            for(int dir{0}; dir < 2; ++dir){
                int nx{x + xx[dir]};
                int ny{y + yy[dir]};
                if(nx > n || ny > m) continue;
                if(B[nx][ny]) continue;
                ret += f(nx, ny, c + A[x][y]);
            }
            return ret;
        }
    };
    int k = A[1][1];
    cout << f(1, 1, k) << "\n";
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
