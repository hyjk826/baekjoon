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
    int n;
    cin >> n;
    vector<vc> board(n, vc(n));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < n; ++j){
            cin >> board[i][j];
        }
    }
    vi ans;
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < n; ++j){
            if(board[i][j] == '1'){
                queue<pi> Q;
                Q.push({i, j});
                board[i][j] = '0';
                int cnt{0};
                while(!Q.empty()){
                    int x{Q.front().first};
                    int y{Q.front().second};
                    Q.pop();
                    cnt++;
                    for(int dir{0}; dir < 4; ++dir){
                        int nx{x + xx[dir]};
                        int ny{y + yy[dir]};
                        if(nx < 0 || nx > n - 1 || ny < 0 || ny > n - 1) continue;
                        if(board[nx][ny] == '1'){
                            board[nx][ny] = '0';
                            Q.push({nx, ny});
                        }
                    }
                }
                ans.push_back(cnt);
            }
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for(auto& i : ans) cout << i << "\n";
}