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
    int n, m, k;
    cin >> n >> m >> k;
    vector<vc> board(n, vc(m));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            cin >> board[i][j];
        }
    }
    while(k--){
        string str;
        cin >> str;
        int a = (int)str.size();
        int xx[]{-1,-1,-1,0,0,1,1,1};
        int yy[]{-1,0,1,-1,1,-1,0,1};
        ll ans{0};
        map<string,int> mp[10][10];
        function<int(int, int, string)> f = [&](int x, int y, string s){
            if(mp[x][y].count(s)) return mp[x][y][s];
            if(board[x][y] != s[0]) return mp[x][y][s] = 0;
            if(s.size() == 1) return mp[x][y][s] = 1;
            mp[x][y][s] = 0;
            for(int dir{0}; dir < 8; ++dir){
                int nx{(x + xx[dir] + n) % n};
                int ny{(y + yy[dir] + m) % m};                
                if(board[nx][ny] == s[1]){
                    mp[x][y][s] += f(nx, ny, s.substr(1));
                }
            }
            return mp[x][y][s];
        };
        for(int i{0}; i < n; ++i){
            for(int j{0}; j < m; ++j){
                if(board[i][j] != str[0]) continue;
                ans += f(i, j, str);
            }
        }
        cout << ans << "\n";
    }
}
