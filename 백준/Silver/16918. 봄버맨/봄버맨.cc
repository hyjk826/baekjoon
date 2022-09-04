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

int main() {
	fastio;
    int n, m, t;
    cin >> n >> m >> t;
    vector<vc> board(n, vc(m));
    vp vec;
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            cin >> board[i][j];
        }
    }
    int xx[]{-1,0,1,0};
    int yy[]{0,1,0,-1};
    if(t % 2 == 0){
        for(int i{0}; i < n; ++i){
            cout << string(m, 'O') << "\n";
        }
    }
    else{
        for(int i{1}; i <= t - 1; ++i){
            if(i & 1){
                vec.clear();
                for(int i{0}; i < n; ++i){
                    for(int j{0}; j < m; ++j){
                        if(board[i][j] == 'O'){
                            vec.push_back({i, j});
                        }
                        else board[i][j] = 'O';
                    }
                }
            }
            else{
                vector<vi> ch(n, vi(m));
                for(auto& i : vec){
                    ch[i.first][i.second] = 1;
                    for(int dir{0}; dir < 4; ++dir){
                        int nx{i.first + xx[dir]};
                        int ny{i.second + yy[dir]};
                        if(nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1) continue;
                        ch[nx][ny] = 1;
                    }
                }
                for(int i{0}; i < n; ++i){
                    for(int j{0}; j < m; ++j){
                        if(ch[i][j]) board[i][j] = '.';
                        else board[i][j] = 'O';
                    }
                }
            }
        }
        for(int i{0}; i < n; ++i){
            for(int j{0}; j < m; ++j){
                cout << board[i][j];
            }
            cout << "\n";
        }
    }
}
	

