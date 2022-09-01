// 2022-09-01
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

int sz;

void f(int x, int y, int k, vector<vi>& board){
    if(k == 0) return;
    vi A, B, C, D;
    for(int j{y}; j < y + k; ++j){
        A.push_back(board[x][j]);
    }
    for(int i{x}; i < x + k; ++i){
        B.push_back(board[i][y + k - 1]);
    }
    for(int j{y + k - 1}; j >= y; --j){
        C.push_back(board[x + k - 1][j]);
    }
    for(int i{x + k - 1}; i >= x; --i){
        D.push_back(board[i][y]);
    }
    for(int j{y}, cnt{0}; j < y + k; ++j, ++cnt){
        board[x][j] = D[cnt];
    }
    for(int i{x}, cnt{0}; i < x + k; ++i, ++cnt){
        board[i][y + k - 1] = A[cnt];
    }
    for(int j{y + k - 1}, cnt{0}; j >= y; --j, ++cnt){
        board[x + k - 1][j] = B[cnt];
    }
    for(int i{x + k - 1}, cnt{0}; i >= x; --i, ++cnt){
        board[i][y] = C[cnt];
    }
    f(x + 1, y + 1, k - 2, board);
}

int main() {
	fastio;
    int n, q;
    cin >> n >> q;
    sz = (1 << n);
    vector<vi> board(sz, vi(sz));
    for(int i{0}; i < sz; ++i){
        for(int j{0}; j < sz; ++j){
            cin >> board[i][j];
        }
    }
    int xx[]{-1,0,1,0};
    int yy[]{0,1,0,-1};
    while(q--){
        int k;
        cin >> k;
        if(k){
            for(int i{0}; i < sz; i += (1 << k)){
                for(int j{0}; j < sz; j += (1 << k)){
                    f(i, j, (1 << k), board);
                }
            }
        }
        vector<vi> ch(sz, vi(sz));
        for(int i{0}; i < sz; ++i){
            for(int j{0}; j < sz; ++j){
                if(board[i][j] == 0) continue;
                int cnt{0};
                for(int dir{0}; dir < 4; ++dir){
                    int nx{i + xx[dir]};
                    int ny{j + yy[dir]};
                    if(nx < 0 || nx > sz - 1 || ny < 0 || ny > sz - 1) continue;
                    if(board[nx][ny] > 0){
                        cnt++;
                    }
                }
                if(cnt < 3) ch[i][j] = 1;
            }
        }
        for(int i{0}; i < sz; ++i){
            for(int j{0}; j < sz; ++j){
                if(ch[i][j] == 1) board[i][j]--;
            }
        }
    }
    int mx{0};
    int sum{0};
    vector<vi> ch(sz, vi(sz));
    for(int i{0}; i < sz; ++i){
        for(int j{0}; j < sz; ++j){
            sum += board[i][j];
            if(ch[i][j] == 0 && board[i][j] > 0){
                ch[i][j] = 1;
                queue<pi> Q;
                Q.push({i, j});
                int cnt{0};
                while(!Q.empty()){
                    int x{Q.front().first};
                    int y{Q.front().second};
                    Q.pop();
                    cnt++;
                    for(int dir{0}; dir < 4; ++dir){
                        int nx{x + xx[dir]};
                        int ny{y + yy[dir]};
                        if(nx < 0 || nx > sz - 1 || ny < 0 || ny > sz - 1) continue;
                        if(ch[nx][ny] == 0 && board[nx][ny] > 0){
                            ch[nx][ny] = 1;
                            Q.push({nx, ny});
                        }
                    }
                }
                mx = max(mx, cnt);
            }
        }
    }
    cout << sum << "\n" << mx;
}

