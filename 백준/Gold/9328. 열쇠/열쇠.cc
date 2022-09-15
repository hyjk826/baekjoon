// 2022-09-15
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
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<vc> board(n, vc(m));
        for(int i{0}; i < n; ++i){
            for(int j{0}; j < m; ++j){
                cin >> board[i][j];
            }
        }
        string str;
        cin >> str;
        vi key(26);
        if(str != "0"){
            for(auto& c : str){
                key[c - 'a'] = 1;
            }
        }
        int xx[]{-1,0,1,0};
        int yy[]{0,1,0,-1};
        int pre{0};
        int ans{0};
        while(1){
            int cnt{0};
            ans = 0;
            vector<vi> ch(n, vi(m));
            queue<pi> Q;
            for(int i{0}; i < n; ++i){
                for(int j{0}; j < m; ++j){
                    if(i == 0 || i == n - 1 || j == 0 || j == m - 1){
                        if(board[i][j] == '.' || board[i][j] == '$') {
                            Q.push({i, j});
                            ch[i][j] = 1;
                        }
                        else if('a' <= board[i][j] && board[i][j] <= 'z'){
                            Q.push({i, j});
                            ch[i][j] = 1;
                            key[board[i][j] - 'a']++;
                        }
                        else if('A' <= board[i][j] && board[i][j] <= 'Z' && key[board[i][j] - 'A']){
                            ch[i][j] = 1;
                            Q.push({i, j});
                        }
                    }
                }
            }
            while(!Q.empty()){
                int x{Q.front().first};
                int y{Q.front().second};
                Q.pop();
                cnt++;
                if(board[x][y] == '$') ans++;
                for(int dir{0}; dir < 4; ++dir){
                    int nx{x + xx[dir]};
                    int ny{y + yy[dir]};
                    if(nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1) continue;
                    if(ch[nx][ny] == 1) continue;
                    if(board[nx][ny] == '.'){
                        Q.push({nx, ny});
                        ch[nx][ny] = 1;
                    }
                    else if('a' <= board[nx][ny] && board[nx][ny] <= 'z'){
                        ch[nx][ny] = 1;
                        key[board[nx][ny] - 'a']++;
                        Q.push({nx, ny});
                    }
                    else if('A' <= board[nx][ny] && board[nx][ny] <= 'Z' && key[board[nx][ny] - 'A']){
                        ch[nx][ny] = 1;
                        Q.push({nx, ny});
                    }
                    else if(board[nx][ny] == '$'){
                        ch[nx][ny] = 1;
                        Q.push({nx, ny});
                    }
                }
            }
            if(pre == cnt) break;
            pre = cnt;
        }
        cout << ans << "\n";
    }
}

