// 2022-09-11
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
vp virus;
vp e;
int board[8][8];
vi ch(3);
int ans{0};
int xx[]{-1,0,1,0};
int yy[]{0,1,0,-1};

void dfs(int L, int k){
    if(L == 3){
        vector<vi> copy(n, vi(m));
        for(int i{0}; i < n; ++i){
            for(int j{0}; j < m; ++j){
                copy[i][j] = board[i][j];
            }
        }
        queue<pi> Q;
        for(int i{0}; i < (int)virus.size(); ++i){
            Q.push({virus[i].first, virus[i].second});
        }
        for(int i{0}; i < 3; ++i){
            copy[e[ch[i]].first][e[ch[i]].second] = 1;
        }
        while(!Q.empty()){
            int x{Q.front().first};
            int y{Q.front().second};
            Q.pop();
            for(int dir{0}; dir < 4; ++dir){
                int nx{x + xx[dir]};
                int ny{y + yy[dir]};
                if(nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1) continue;
                if(copy[nx][ny] == 0){
                    copy[nx][ny] = 2;
                    Q.push({nx, ny});
                }
            }
        }
        int cnt{0};
        for(int i{0}; i < n; ++i){
            for(int j{0}; j < m; ++j){
                if(copy[i][j] == 0) cnt++;
            }
        }
        ans = max(ans, cnt);
    }
    else{
        for(int i{k + 1}; i < (int)e.size(); ++i){
            ch[L] = i;
            dfs(L + 1, i);
        }
    }
}

int main(){
    fastio;
    cin >> n >> m;
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            cin >> board[i][j];
            if(board[i][j] == 2) virus.push_back({i, j});
            else if(board[i][j] == 0) e.push_back({i, j});
        }
    }
    dfs(0, -1);
    cout << ans;
}