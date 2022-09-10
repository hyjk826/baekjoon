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

int xx[]{-1,0,1,0};
int yy[]{0,1,0,-1};

int main(){
    fastio;
    int n, m;
    cin >> m >> n;
    vector<vi> board(n, vi(m));
    int zero{0};
    queue<pi> Q;
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            cin >> board[i][j];
            if(board[i][j] == 0){
                zero++;
            }
            else if(board[i][j] == 1){
                Q.push({i, j});
            }
        }
    }
    if(zero == 0) cout << 0 << "\n";
    else{
        int cnt{0};
        while(1){
            int sz = (int)Q.size();
            bool flag = false;
            while(sz--){
                int x{Q.front().first};
                int y{Q.front().second};
                Q.pop();
                for(int dir{0}; dir < 4; ++dir){
                    int nx{x + xx[dir]};
                    int ny{y + yy[dir]};
                    if(nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1) continue;
                    if(board[nx][ny] == 0){
                        board[nx][ny] = 1;
                        flag = true;
                        Q.push({nx, ny});
                    }

                }
            }
            if(!flag) break;
            cnt++;
        }
        zero = 0;
        for(int i{0}; i < n; ++i){
            for(int j{0}; j < m; ++j){
                if(board[i][j] == 0) zero++;
            }
        }
        if(zero) cout << -1 << "\n";
        else cout << cnt << "\n";
    }
}