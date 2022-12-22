// 2022-12-22
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

struct st{
    int x, y, cnt;
};



int main(){
	fastio;
	int n, m, k;
    cin >> n >> m >> k;
    vector<vc> board(n, vc(m));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            cin >> board[i][j];
        }
    }
    int ans{0};
    int xx[]{-1,0,1,0};
    int yy[]{0,1,0,-1};
    vector<vi> ch(n, vi(m));
    ch[n - 1][0] = 1;
    function<void(int,int,int)> dfs = [&](int L, int x, int y){
        if(L == k - 1){
            if(x == 0 && y == m - 1) ans++;
        }
        else{
            for(int dir{0}; dir < 4; ++dir){
                int nx{x + xx[dir]};
                int ny{y + yy[dir]};
                if(nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1) continue;
                if(board[nx][ny] == 'T') continue;
                if(ch[nx][ny] == 0){
                    ch[nx][ny] = 1;
                    dfs(L + 1, nx, ny);
                    ch[nx][ny] = 0;       
                }
            }
        }
    };
    dfs(0, n - 1, 0);
    cout << ans;
}
	
