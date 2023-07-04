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


void solve(int n, int m){
    vector<vc> board(n, vc(m));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            cin >> board[i][j];
        }
    }
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            if(board[i][j] == '*') continue;
            int cnt{0};
            for(int dir{0}; dir < 8; ++dir){
                int nx{i + xx[dir]};
                int ny{j + yy[dir]};
                if(nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1) continue;
                if(board[nx][ny] == '*') cnt++;
            }
            board[i][j] = char('0' + cnt);
        }
    }
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            cout << board[i][j];
        }
        cout << "\n";
    }
}

int main(){
	fastio;
    int n, m;
	while(cin >> n >> m){
        if(n == 0 && m == 0) break;
		solve(n, m);
	}
}
