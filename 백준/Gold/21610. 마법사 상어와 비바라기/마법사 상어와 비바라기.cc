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

int main(){
	fastio;
    int n, m;
    cin >> n >> m;
    vector<vi> board(n, vi(n));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < n; ++j){
            cin >> board[i][j];
        }
    }
    int xx[]{0,-1,-1,-1,0,1,1,1};
    int yy[]{-1,-1,0,1,1,1,0,-1};
    vp query(m);
    for(int i{0}; i < m; ++i){
        cin >> query[i].first >> query[i].second;
        query[i].first--;
    }
    int ax[]{-1,-1,1,1};
    int ay[]{-1,1,-1,1};
    queue<pi> Q;
    Q.push({n - 1, 0});
    Q.push({n - 1, 1});
    Q.push({n - 2, 0});
    Q.push({n - 2, 1});
    for(int i{0}; i < m; ++i){
        vector<vi> ch(n, vi(n));
        vector<vi> temp(n, vi(n));
        int sz = Q.size();
        for(int j{0}; j < sz; ++j){             
            int op = query[i].first;
            int d = query[i].second;
            auto top = Q.front();
            int x = (Q.front().first + xx[op] * d + n * 100) % n;
            int y = (Q.front().second + yy[op] * d + n * 100) % n;
            Q.pop();
            board[x][y]++;
            Q.push({top.first, top.second});
        }
        while(!Q.empty()){
            int op = query[i].first;
            int d = query[i].second;
            int x = (Q.front().first + xx[op] * d + n * 100) % n;
            int y = (Q.front().second + yy[op] * d + n * 100) % n;
            Q.pop();
            for(int dir{0}; dir < 4; ++dir){
                int nx{x + ax[dir]};
                int ny{y + ay[dir]};
                if(nx < 0 || nx > n - 1 || ny < 0 || ny > n - 1 || board[nx][ny] == 0) continue;
                temp[x][y]++;
            }
            ch[x][y] = 1;
        }
        for(int j{0}; j < n; ++j){
            for(int k{0}; k < n; ++k){
                board[j][k] += temp[j][k];
                if(ch[j][k]) continue;
                if(board[j][k] < 2) continue;
                board[j][k] -= 2;
                Q.push({j, k});
            }
        }
    }
    int ans{0};
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < n; ++j){
            ans += board[i][j];
        }
    }
    cout << ans;
    
}
