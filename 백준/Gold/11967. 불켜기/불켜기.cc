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
    vector<vi> ch(n, vi(n));
    vp A[100][100];
    for(int i{0}; i < m; ++i){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--; b--; c--; d--;
        A[a][b].push_back({c, d});
    }
    ch[0][0] = 1;
    queue<pi> Q;
    Q.push({0, 0});
    int xx[]{-1,0,1,0};
    int yy[]{0,1,0,-1};
    while(1){
        int cnt{0};
        int sz = Q.size();
        for(int i{0}; i < sz; ++i){
            int x{Q.front().first};
            int y{Q.front().second};
            Q.pop();           
            while(!A[x][y].empty()){
                int a = A[x][y].back().first;
                int b = A[x][y].back().second;
                if(ch[a][b] == 0) {
                    ch[a][b] = 2;
                    cnt++;
                }
                A[x][y].pop_back();
            }
            for(int dir{0}; dir < 4; ++dir){
                int nx{x + xx[dir]};
                int ny{y + yy[dir]};
                if(nx < 0 || nx > n - 1 || ny < 0 || ny > n - 1) continue;
                if(ch[nx][ny] == 2){
                    ch[nx][ny] = 1;
                    Q.push({nx, ny});
                    cnt++;
                }
            }
            Q.push({x, y});
        }
        if(cnt == 0) break;
    }
    int ans{0};
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < n; ++j){
            if(ch[i][j]) ans++;
        }
    }
    cout << ans;
}
