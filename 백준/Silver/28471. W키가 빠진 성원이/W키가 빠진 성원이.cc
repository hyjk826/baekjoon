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
    vector<vc> board(n, vc(n));
    int sx, sy;
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < n; ++j){
            cin >> board[i][j];
            if(board[i][j] == 'F'){
                sx = i; sy = j;
            }
        }
    }
    int xx[]{-1,-1,-1,0,0,1,1};
    int yy[]{-1,0,1,-1,1,-1,1};
    queue<pi> Q;
    int ans{0};
    Q.push({sx, sy});
    while(!Q.empty()){
        int x{Q.front().first};
        int y{Q.front().second};
        Q.pop();
        ans++;
        for(int dir{0}; dir < 7; ++dir){
            int nx{x + xx[dir]};
            int ny{y + yy[dir]};
            if(nx < 0 || nx > n - 1 || ny < 0 || ny > n - 1) continue;
            if(board[nx][ny] == '.'){
                board[nx][ny] = 'F';
                Q.push({nx, ny});
            }
        }
    }
    cout << ans - 1 << "\n";
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
