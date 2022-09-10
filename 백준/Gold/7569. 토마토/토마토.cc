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

int board[100][100][100];

struct st{
    int h, x, y;
};

int main(){
    fastio;
    int n, m, k;
    cin >> m >> n >> k;
    int zero{0};
    queue<st> Q;
    for(int i{0}; i < k; ++i){
        for(int j{0}; j < n; ++j){
            for(int k{0}; k < m; ++k){
                cin >> board[i][j][k];
                if(board[i][j][k] == 0) zero++;
                else if(board[i][j][k] == 1){
                    Q.push({i, j, k});
                }
            }
        }
    }
    int ans{0};
    int hh[] = {1,-1,0,0,0,0};
    int xx[] = {0,0,0,-1,0,1};
    int yy[] = {0,0,1,0,-1,0};
    while(!Q.empty()){
        int sz = (int)Q.size();
        bool flag = false;
        while(sz--){
            int h{Q.front().h};
            int x{Q.front().x};
            int y{Q.front().y};
            Q.pop();
            for(int dir{0}; dir < 6; ++dir){
                int nh{h + hh[dir]};
                int nx{x + xx[dir]};
                int ny{y + yy[dir]};
                if(nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1 || nh < 0 || nh > k - 1) continue;
                if(board[nh][nx][ny] == 0){
                    board[nh][nx][ny] = 1;
                    zero--;
                    flag= true;
                    Q.push({nh, nx, ny});
                }
            }
        }
        if(!flag) break;
        ans++;
    }
    if(zero == 0) cout << ans;
    else cout << -1;
}