// 2022-01-20
#include <bits/stdc++.h>
#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define vi vector<int>
#define pi pair<int, int>
#define ll long long
#define MAX 2147000000
#define MOD 998244353LL
using namespace std;

int xx[]{-1,0,1,0};
int yy[]{0, 1, 0, -1};

int main(){
    fastio;
    int n, m;
    cin >> n >> m;
    queue<pi> waterQ;
    queue<pi> waterAfterQ;
    queue<pi> LQ;
    queue<pi> LAfterQ;
    vector<pi> L;
    vector<vector<char> > board(n, vector<char>(m));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            cin >> board[i][j];
            if(board[i][j] == 'L'){
                L.push_back({i, j});
                waterQ.push({i, j});
            }
            else if(board[i][j] == '.'){
                waterQ.push({i, j});
            }
        }
    }
    LQ.push({L[0].first, L[0].second});
    vector<vi> ch(n, vi(m));
    ch[L[0].first][L[0].second] = 1;
    int ans{0};
    while(1){
        while(!LQ.empty()){
            int x{LQ.front().first};
            int y{LQ.front().second};
            LQ.pop();
            if(x == L[1].first && y == L[1].second){
                cout << ans;
                return 0;
            }
            for(int i{0}; i < 4; ++i){
                int nx{x + xx[i]};
                int ny{y + yy[i]};
                if(nx < 0 || nx > n - 1 || ny < 0 || ny > m -1 ) continue;
                if(ch[nx][ny] == 0){
                    ch[nx][ny] = 1;
                    if(board[nx][ny] == 'X'){
                        LAfterQ.push({nx, ny});
                    }
                    else{
                        LQ.push({nx,ny});
                    }
                }
            }
        }
        while(!waterQ.empty()){
            int x{waterQ.front().first};
            int y{waterQ.front().second};
            waterQ.pop();
            for(int i{0}; i < 4; ++i){
                int nx{x + xx[i]};
                int ny{y + yy[i]};
                if(nx < 0 || nx > n - 1 || ny < 0 || ny > m -1 ) continue;
                if(board[nx][ny] == 'X'){
                    board[nx][ny] = '.';
                    waterAfterQ.push({nx, ny});
                }
            }
        }
        LQ = LAfterQ;
        waterQ = waterAfterQ;
        while(!LAfterQ.empty()) LAfterQ.pop();
        while(!waterAfterQ.empty()) waterAfterQ.pop();
        ans++;
    }
}
