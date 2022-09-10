// 2022-09-10
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define vs vector<string>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int n, m;
int board[500][500];
int xx[]{-1,0,1,0};
int yy[]{0,1,0,-1};
vector<vi> ch(500, vi(500));
int ans{0};

bool bound(int x, int y){
    if(x < 0 || x > n - 1 || y < 0 || y > m - 1) return false;
    return true;
}

void dfs(int L, int x, int y, int sum){
    if(L == 4){
        ans = max(ans, sum);
    }
    else{
        for(int dir{0}; dir < 4; ++dir){
            int nx{x + xx[dir]};
            int ny{y + yy[dir]};
            if(bound(nx, ny) && ch[nx][ny] == 0){
                ch[nx][ny] = 1;
                dfs(L + 1, nx, ny, sum + board[nx][ny]);
                ch[nx][ny] = 0;
            }
        }
    }
}

int main(){
    fastio;
    cin >> n >> m;
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            cin >> board[i][j];
        }
    }
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            ch[i][j] = 1;
            dfs(1, i, j, board[i][j]);
            ch[i][j] = 0;
        }
    }
    for(int i{0}; i < n; ++i){
        for(int j{1}; j < m - 1; ++j){
            int sum = board[i][j - 1] + board[i][j] + board[i][j + 1];
            if(i){
                ans = max(ans, sum + board[i - 1][j]);
            }
            if(i < n - 1){
                ans = max(ans, sum + board[i + 1][j]);
            }
        }
    }
    for(int j{0}; j < m; ++j){
        for(int i{1}; i < n - 1; ++i){
            int sum = board[i - 1][j] + board[i][j] + board[i + 1][j];
            if(j){
                ans = max(ans, sum + board[i][j - 1]);
            }
            if(j < m - 1){
                ans = max(ans, sum + board[i][j + 1]);
            }
        }
    }
    cout << ans;
}