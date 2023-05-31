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
    ll n, m, k, X;
    cin >> n >> m >> k >> X;
    vector<vl> board(n, vl(m));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            cin >> board[i][j];
        }
    }
    ll l{0}, r{X};
    ll ans{-1};
    int xx[]{-1,0,1,0};
    int yy[]{0,1,0,-1};
    while(l <= r){
        ll mid{(l + r) >> 1};
        int cnt{0};
        vector<vi> ch(n, vi(m));
        for(int i{0}; i < n; ++i){
            for(int j{0}; j < m; ++j){
                if(ch[i][j] || board[i][j] >= X - mid) continue;
                queue<pi> Q;
                Q.push({i, j});
                ch[i][j] = 1;
                bool ok = false;
                int c{0};
                while(!Q.empty()){
                    int x{Q.front().first};
                    int y{Q.front().second};
                    Q.pop();
                    c++;
                    for(int dir{0}; dir < 4; ++dir){
                        int nx{x + xx[dir]};
                        int ny{y + yy[dir]};
                        if(nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1) continue;
                        if(abs(board[nx][ny] - board[x][y]) > mid) ok = true;
                        if(board[nx][ny] >= X - mid) continue;
                        if(ch[nx][ny] == 0){
                            ch[nx][ny] = 1;
                            Q.push({nx, ny});
                        }
                    }
                }
                if(ok) cnt += c;
            }
        }
        if(cnt <= k){
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
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
