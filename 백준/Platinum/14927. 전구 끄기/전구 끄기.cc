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

void solve(){
    int n;
    cin >> n;
    vector<vi> board(n, vi(n));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < n; ++j){
            cin >> board[i][j];
        }
    }
    int ans{MAX};
    int xx[]{-1,0,1,0};
    int yy[]{0,1,0,-1};
    for(int i{0}; i < (1 << n); ++i){
        auto tmp = board;
        int cnt{0};
        for(int j{0}; j < n; ++j){
            if((i >> j) & 1) {
                cnt++;
                tmp[0][j] ^= 1;
                for(int dir{0}; dir < 4; ++dir){
                    int nx{0 + xx[dir]};
                    int ny{j + yy[dir]};
                    if(nx < 0 || nx > n - 1 || ny < 0 || ny > n - 1) continue;
                    tmp[nx][ny] ^= 1;
                }
            }
        }
        for(int j{1}; j < n; ++j){
            for(int k{0}; k < n; ++k){
                if(tmp[j - 1][k]){
                    cnt++;
                    tmp[j][k] ^= 1;
                    for(int dir{0}; dir < 4; ++dir){
                        int nx{j + xx[dir]};
                        int ny{k + yy[dir]};
                        if(nx < 0 || nx > n - 1 || ny < 0 || ny > n - 1) continue;
                        tmp[nx][ny] ^= 1;
                    }
                }
            }
        }
        int c{0};
        for(int j{0}; j < n; ++j){
            c += tmp[n - 1][j];
        }
        if(c == 0) ans = min(ans, cnt);
    }
    if(ans == MAX) ans = -1;
    cout << ans;
}

int main(){
	fastio;
	int t;
	t = 1;
	while(t--){
		solve();
	}
}
