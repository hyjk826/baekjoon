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

int xx[]{-1,-1,-1,0,0,1,1,1};
int yy[]{-1,0,1,-1,1,-1,0,1};

void solve(){
	int n, m;
    cin >> n >> m;
    vp vec(n * m + 1);
    vector<vi> board(n, vi(m));
    vector<vi> ans(n, vi(m));
    vp pos(n * m);
    vector<vp> tmp(n, vp(m));
    vi A;
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            cin >> board[i][j];
            A.push_back(board[i][j]);
        }
    }
    sort(A.begin(), A.end());
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            board[i][j] = lower_bound(A.begin(), A.end(), board[i][j]) - A.begin();
            pos[board[i][j]] = {i,j};
        }
    }
    for(int i{0}; i < n * m; ++i){
        int mn{MAX};
        int x = pos[i].first;
        int y = pos[i].second;
        int a, b;
        a = b = -1;
        for(int dir{0}; dir < 8; ++dir){
            int nx{x + xx[dir]};
            int ny{y + yy[dir]};
            if(nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1) continue;
            if(board[nx][ny] < i){
                if(mn > board[nx][ny]){
                    a = nx; b = ny;
                    mn = board[nx][ny];
                }
            }
        }
        if(a == -1){
            ans[x][y]++;
            tmp[x][y] = {x, y};
        }
        else{
            ans[tmp[a][b].first][tmp[a][b].second]++;
            tmp[x][y] = {tmp[a][b].first, tmp[a][b].second};
        }
    }
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}