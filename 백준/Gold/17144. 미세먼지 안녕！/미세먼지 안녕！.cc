// 2022-09-12
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
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int xx[]{-1,0,1,0};
int yy[]{0,1,0,-1};

int main() {
	fastio;
    int n, m, t;
    cin >> n >> m >> t;
    vector<vi> board(n, vi(m));
    int a{-1}, b{-1};
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            cin >> board[i][j];
            if(board[i][j] == -1){
                if(a == -1) a = i;
                else b = i;
                board[i][j] = 0;
            }
        }
    }
    for(int i{0}; i < t; ++i){
        vector<vi> board2(n, vi(m));
        for(int j{0}; j < n; ++j){
            for(int k{0}; k < m; ++k){
                if(board[j][k]){
                    int cnt{0};
                    int plus = board[j][k] / 5;
                    for(int dir{0}; dir < 4; ++dir){
                        int nx{j + xx[dir]};
                        int ny{k + yy[dir]};
                        if(nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1) continue;
                        if(ny == 0 && (nx == a || nx == b)) continue;
                        board2[nx][ny] += plus;
                        cnt++;
                    }
                    board2[j][k] += board[j][k] - cnt * plus;
                }
            }
        }
        for(int j{a - 1}; j >= 1; --j){
            board2[j][0] = board2[j - 1][0];
        }
        for(int j{0}; j < m - 1; ++j){
            board2[0][j] = board2[0][j + 1];
        }
        for(int j{0}; j <= a - 1; ++j){
            board2[j][m - 1] = board2[j + 1][m - 1];
        }
        for(int j{m - 1}; j >= 2; --j){
            board2[a][j] = board2[a][j - 1];
        }
        board2[a][1] = 0;
        for(int j{b + 1}; j <= n - 2; ++j){
            board2[j][0] = board2[j + 1][0];
        }
        for(int j{0}; j<= m - 2; ++j){
            board2[n - 1][j] = board2[n - 1][j + 1];
        }
        for(int j{n - 1}; j >= b + 1; --j){
            board2[j][m - 1] = board2[j - 1][m - 1];
        }
        for(int j{m - 1}; j >= 2; --j){
            board2[b][j] = board2[b][j - 1];
        }
        board2[b][1] = 0;
        board = board2;
    }
    int ans{0};
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            ans += board[i][j];
        }
    }
    cout << ans;
}
	

