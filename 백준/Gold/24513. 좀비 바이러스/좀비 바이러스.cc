// 2022-09-17
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
    queue<pi> A, B;
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            cin >> board[i][j];
            if(board[i][j] == 1){
                A.push({i, j});
            }
            else if(board[i][j] == 2){ 
                B.push({i, j});
            }
        }
    }
    int a{0}, b{0}, c{0};
    int xx[]{-1,0,1,0};
    int yy[]{0,1,0,-1};
    while(1){
        set<pi> st;
        int a = (int)A.size();
        int b = (int)B.size();
        for(int i{0}; i < a; ++i){
            int x{A.front().first};
            int y{A.front().second};
            A.pop();
            for(int dir{0}; dir < 4; ++dir){
                int nx{x + xx[dir]};
                int ny{y + yy[dir]};
                if(nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1) continue;
                if(board[nx][ny] == 0){
                    board[nx][ny] += 1;
                    st.insert({nx, ny});
                }                
            }
        }
        for(int i{0}; i < b; ++i){
            int x{B.front().first};
            int y{B.front().second};
            B.pop();
            for(int dir{0}; dir < 4; ++dir){
                int nx{x + xx[dir]};
                int ny{y + yy[dir]};
                if(nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1) continue;
                if(board[nx][ny] == 0 || (board[nx][ny] == 1 && st.count({nx, ny}))){
                    board[nx][ny] += 2;
                    if(!st.count({nx, ny})){
                        B.push({nx, ny});
                    }
                    else st.erase({nx, ny});
                }     
            }
        }
        for(auto& i : st){
            A.push({i.first, i.second});
        }
        if(A.empty() && B.empty()) break;
    }
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            if(board[i][j] == 1) a++;
            else if(board[i][j] == 2) b++;
            else if(board[i][j] == 3) c++;
        }
    }
    cout << a << " " << b << " " << c;
}
	

