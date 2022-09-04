// 2022-09-05
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

int n, m;
char board[50][50];
int ch[50][50]{};
int finish[50][50]{};
int xx[]{-1,0,1,0};
int yy[]{0,1,0,-1};

void dfs(int x, int y, int px, int py){
    for(int dir{0}; dir < 4; ++dir){
        int nx{x + xx[dir]};
        int ny{y + yy[dir]};
        if(nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1) continue;
        if(nx == px && ny == py) continue;
        if(board[nx][ny] == board[x][y]){
            if(ch[nx][ny] == 0){
                ch[nx][ny] = 1;
                dfs(nx, ny, x, y);
            }
            else if(finish[nx][ny] == 0){
                cout << "Yes";
                exit(0);
            }
        }
    }
    finish[x][y] = 1;
}

int main() {
	fastio;    
    cin >> n >> m;
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            cin >> board[i][j];
        }
    }
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            if(ch[i][j] == 0){
                ch[i][j] = 1;
                dfs(i, j, -1, -1);
            }
        }
    }
    cout << "No";
}
	

