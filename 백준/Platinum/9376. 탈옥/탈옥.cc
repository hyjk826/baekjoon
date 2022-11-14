// 2022-11-14
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

int n, m;


struct st{
    int x, y, w;
    bool operator< (const st& a) const{
        return w > a.w;
    }
};

vector<vi> f(int sx, int sy, vector<vc>& board){
    vector<vi> dijk(n + 2,  vi(m + 2, MAX));
    dijk[sx][sy] = 0;
    priority_queue<st> pQ;
    pQ.push({sx, sy, 0});
    int xx[]{-1,0,1,0};
    int yy[]{0,1,0,-1};
    while(!pQ.empty()){
        int x{pQ.top().x};
        int y{pQ.top().y};
        int w{pQ.top().w};
        pQ.pop();
        if(dijk[x][y] < w) continue;
        for(int dir{0}; dir < 4; ++dir){
            int nx{x + xx[dir]};
            int ny{y + yy[dir]};
            if(nx < 0 || nx > n + 1 || ny < 0 || ny > m + 1 || board[nx][ny] == '*') continue;
            int nw = w;
            if(board[nx][ny] == '#') nw++;
            if(dijk[nx][ny] > nw){
                dijk[nx][ny] = nw;
                pQ.push({nx, ny, nw});
            }
        }
    }
    return dijk;
}



int main() {
	fastio;
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        int sx, sy, tx, ty;
        sx = -1;
        vector<vc> board(n + 2, vc(m + 2));
        for(int i{1}; i <= n; ++i){
            for(int j{1}; j <= m; ++j){
                cin >> board[i][j];
                if(board[i][j] == '$'){
                    if(sx == -1){
                        sx = i;
                        sy = j;
                    }
                    else{
                        tx = i;
                        ty = j;
                    }
                }
            }
        }        
        auto A = f(0, 0, board);
        auto B = f(sx, sy, board);
        auto C = f(tx, ty, board);
        int ans{MAX};
        for(int i{0}; i <= n + 1; ++i){
            for(int j{0}; j <= m + 1; ++j){
                if(board[i][j] == '*') continue;
                int k = A[i][j] + B[i][j] + C[i][j];
                if(board[i][j] == '#') k -= 2;
                ans = min(ans, k);
            }
        }
        cout << ans << "\n";
    }
}
	

