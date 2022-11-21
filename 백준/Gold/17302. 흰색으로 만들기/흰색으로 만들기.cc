// 2022-11-20
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

int main() {
	fastio;	
	int n, m;
    cin >> n >> m;
    vector<vi> board(n, vi(m));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            char c;
            cin >> c;
            if(c == 'B') board[i][j] = 1; 
        }
    }
    vector<vi> ans(n, vi(m, 2));
    int xx[]{-1,0,1,0};
    int yy[]{0,1,0,-1};
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            for(int dir{0}; dir < 4; ++dir){
                int nx{i + xx[dir]};
                int ny{j + yy[dir]};
                if(nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1) continue;
                board[nx][ny] ^= 1;
            }
        }
    }
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            if(board[i][j] == 1){
                ans[i][j] = 3;
            }
        }
    }
    cout << 1 << "\n";
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            cout << ans[i][j];
        }
        cout << "\n";
    }
}
	

