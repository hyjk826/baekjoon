// 2022-08-15
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

struct st{
    int x1, y1, x2, y2;
};

struct info{
    int x, y, cnt;
};

int main() {
	fastio;
    int n, m, k;
    cin >> n >> m >> k;
    vector<vi> board(n, vi(n));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < n; ++j){
            cin >> board[i][j];
        }
    }
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    int xx[]{-1,0,1,0};
    int yy[]{0,1,0,-1};
    vector<st> vec(m);
    for(int i{0}; i < m; ++i){
        cin >> vec[i].x1 >> vec[i].y1 >> vec[i].x2 >> vec[i].y2;
        vec[i].x1--;
        vec[i].y1--;
        vec[i].x2--;
        vec[i].y2--;
        board[vec[i].x1][vec[i].y1] = i + 2;
    }
    for(int i{0}; i < m; ++i){
        queue<info> Q;
        Q.push({x, y, 0});
        vector<vi> ch(n, vi(n));
        ch[x][y] = 1;
        vector<info> A;
        while(!Q.empty()){
            int x{Q.front().x};
            int y{Q.front().y};
            int cnt{Q.front().cnt};
            Q.pop();
            if(board[x][y] >= 2){
                A.push_back({x, y, cnt});
            }
            for(int dir{0}; dir < 4; ++dir){
                int nx{x + xx[dir]};
                int ny{y + yy[dir]};
                if(nx < 0 || nx > n - 1 || ny < 0 || ny > n - 1) continue;
                if(ch[nx][ny] == 0 && board[nx][ny] != 1){
                    ch[nx][ny] = 1;
                    Q.push({nx, ny, cnt + 1});
                }
            }
        }
        sort(A.begin(), A.end(), [&](info a, info b){
            if(a.cnt == b.cnt){
                if(a.x == b.x){
                    return a.y < b.y;
                }
                else return a.x < b.x;
            }
            else return a.cnt < b.cnt;
        });
        if(A.empty() || k < A[0].cnt){
            k = -1;
            break;
        }
        else{
            k -= A[0].cnt;
            int index = board[A[0].x][A[0].y] - 2;
            board[A[0].x][A[0].y] = 0;            
            Q.push({A[0].x, A[0].y, 0});
            vector<vi> ch(n, vi(n));
            ch[A[0].x][A[0].y] = 1;
            int c{-1};
            while(!Q.empty()){
                int x{Q.front().x};
                int y{Q.front().y};
                int cnt{Q.front().cnt};
                if(x == vec[index].x2 && y == vec[index].y2){
                    c = cnt;
                    break;
                }
                Q.pop();
                for(int dir{0}; dir < 4; ++dir){
                    int nx{x + xx[dir]};
                    int ny{y + yy[dir]};
                    if(nx < 0 || nx > n - 1 || ny < 0 || ny > n - 1) continue;
                    if(ch[nx][ny] == 0 && board[nx][ny] != 1){
                        ch[nx][ny] = 1;
                        Q.push({nx, ny, cnt + 1});
                    }
                }
            }
            if(c == -1 || k < c){
                k = -1;
                break;
            }
            else{
                k += c;
                x = vec[index].x2;
                y = vec[index].y2;
            }
        }
    }
    cout << k;
}

