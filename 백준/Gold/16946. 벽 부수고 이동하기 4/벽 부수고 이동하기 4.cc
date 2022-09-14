// 2022-09-14
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

int main() {
	fastio;
    int n, m;
    cin >> n >> m;
    vector<vi> board(n, vi(m));    
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            char c;
            cin >> c;
            board[i][j] = c - '0';
        }
    }
    int xx[]{-1,0,1,0};
    int yy[]{0,1,0,-1};
    int c{1};
    vector<vi> cnt(n, vi(m));
    vector<vi> com(n, vi(m));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            if(cnt[i][j] == 0 && board[i][j] == 0){
                vp vec;
                queue<pi> Q;
                Q.push({i, j});
                cnt[i][j] = 1;
                while(!Q.empty()){
                    int x{Q.front().first};
                    int y{Q.front().second};
                    Q.pop();
                    vec.push_back({x, y});
                    for(int dir{0}; dir < 4; ++dir){
                        int nx{x + xx[dir]};
                        int ny{y + yy[dir]};
                        if(nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1 || board[nx][ny] == 1 || cnt[nx][ny] == 1) continue;
                        cnt[nx][ny] = 1;
                        Q.push({nx, ny});
                    }
                }
                int sz = (int)vec.size();
                for(auto& k : vec){
                    cnt[k.first][k.second] = sz;
                    com[k.first][k.second] = c;
                }
                c++;
            }
        }
    }
    vector<vi> ans(n, vi(m));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            if(board[i][j] == 1){
                int sum{1};
                set<int> st;
                for(int dir{0}; dir < 4; ++dir){
                    int nx{i + xx[dir]};
                    int ny{j + yy[dir]};
                    if(nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1) continue;
                    if(!st.count(com[nx][ny])){
                        sum += cnt[nx][ny];
                        st.insert(com[nx][ny]);
                    }
                }
                ans[i][j] = sum;
                ans[i][j] %= 10;
            }
        }
    }
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            cout << ans[i][j];
        }
        cout << "\n";
    }
}
