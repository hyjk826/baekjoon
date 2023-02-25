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
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    x1--; y1--; x2--; y2--;
    vector<vc> board(n, vc(m));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            cin >> board[i][j];
        }
    }
    int ans{0};
    while(1){
        vector<vi> ch(n, vi(m));
        queue<pi> Q;
        Q.push({x1, y1});
        bool flag = false;
        int xx[]{-1,0,1,0};
        int yy[]{0,1,0,-1};
        while(!Q.empty()){
            int x{Q.front().first};
            int y{Q.front().second};
            Q.pop();
            for(int dir{0}; dir < 4; ++dir){
                int nx{x + xx[dir]};
                int ny{y + yy[dir]};
                if(nx < 0 || nx > n -1 || ny < 0 || ny > m - 1) continue;
                if(ch[nx][ny] == 0){
                    ch[nx][ny] = 1;
                    if(board[nx][ny] == '1'){
                        board[nx][ny] = '0';
                        continue;
                    }
                    else if(board[nx][ny] == '#'){
                        flag = true;;
                        break;
                    }
                    Q.push({nx,ny});
                }
            }
            if(flag) break;
        }
        ans++;
        if(flag) break;
    }
    cout << ans;
}
