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

ll board[502][502];
int ch[502][502];
int xx[]{-1,0,1,0};
int yy[]{0,1,0,-1};


void solve(){
	int n, m;
    cin >> n;
    for(int i{0}; i < n; ++i){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if(x1 > x2) swap(x1, x2);
        if(y1 > y2) swap(y1, y2);
        board[x1][y1] += 1;
        board[x1][y2 + 1] -= 1;
        board[x2 + 1][y1] -= 1;
        board[x2 + 1][y2 + 1] += 1;
    }
    cin >> m;
    for(int i{0}; i < m; ++i){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if(x1 > x2) swap(x1, x2);
        if(y1 > y2) swap(y1, y2);
        board[x1][y1] += MAX;
        board[x1][y2 + 1] -= MAX;
        board[x2 + 1][y1] -= MAX;
        board[x2 + 1][y2 + 1] += MAX;
    }
    for(int i{0}; i <= 500; ++i){
        for(int j{1}; j <= 500; ++j){
            board[i][j] += board[i][j - 1];
        }
    }
    for(int j{0}; j <= 500; ++j){
        for(int i{1}; i <= 500; ++i){
            board[i][j] += board[i - 1][j];
        }
    }
    memset(ch, -1, sizeof(ch));
    deque<pi> dQ;
    dQ.push_back({0, 0});
    ch[0][0] = 0;
    while(!dQ.empty()){
        int x{dQ.front().first};
        int y{dQ.front().second};
        dQ.pop_front();
        for(int dir{0}; dir < 4; ++dir){
            int nx{x + xx[dir]};
            int ny{y + yy[dir]};
            if(nx < 0 || nx > 500 || ny < 0 || ny > 500) continue;
            if(board[nx][ny] >= MAX) continue;
            if(board[nx][ny] == 0) {
                if(ch[nx][ny] == -1) {
                    ch[nx][ny] = ch[x][y];
                    dQ.push_front({nx, ny});
                }
            }
            else{
                if(ch[nx][ny] == -1){
                    ch[nx][ny] = ch[x][y] + 1;
                    dQ.push_back({nx, ny});
                }
            }
        }
    }
    cout << ch[500][500] << "\n";
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
