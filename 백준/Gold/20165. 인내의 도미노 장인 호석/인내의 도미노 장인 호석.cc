// 2023-01-21
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
    int n, m, r;
    cin >> n >> m >> r;
    vector<vi> board(n, vi(m));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            cin >> board[i][j];
        }
    }
    vector<vi> ch(n, vi(m, 1));
    int ans{0};
    int xx[]{0, 0, 1, -1};
    int yy[]{1,-1, 0, 0};
    string str = "EWSN";
    for(int i{0}; i < r; ++i){
        int x, y; char c;
        cin >> x >> y >> c;
        x--; y--;
        int dir = str.find(c);
        int mx, my;
        mx = x;
        my = y;
        if(ch[x][y] == 1){
            int cnt{0};
            while(1){
                if(x < 0 || x > n - 1 || y < 0  || y > m - 1) break;
                if(ch[x][y] == 1){
                    ch[x][y] = 0;
                    if(dir == 0) my = max(my, y + yy[dir] * (board[x][y] - 1));
                    else if(dir == 1) my = min(my, y + yy[dir] * (board[x][y] - 1));
                    else if(dir == 2) mx = max(mx, x + xx[dir] * (board[x][y] - 1));
                    else mx = min(mx, x + xx[dir] * (board[x][y] - 1));                      
                    cnt++;
                }                
                if(x == mx &&  y == my) break;
                x += xx[dir];
                y += yy[dir];
            }
            ans += cnt;
        }
        cin >> x >> y;
        x--; y--;
        ch[x][y] = 1;
    }
    cout << ans << "\n";
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            if(ch[i][j]) cout << "S ";
            else cout << "F ";
        }
        cout << "\n";
    }
}
