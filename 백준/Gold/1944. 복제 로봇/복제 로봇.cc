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
    int n, k;
    cin >> n >> k;
    vector<vi> board(n, vi(n));
    int cnt{2};
    int sx, sy;
    vp A;
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < n; ++j){
            char c;
            cin >> c;
            if(c == '1') board[i][j] = -1;
            else if(c == 'S'){
                board[i][j] = 1;
                sx = i; sy = j;
            }
            else if(c == 'K'){
                board[i][j] = cnt++;
                A.push_back({i, j});
            }
        }
    }
    queue<pi> Q;
    vector<vi> ch(n, vi(n, -1));
    vector<vi> dist(k + 2, vi(k + 2, -1));
    Q.push({sx, sy});
    ch[sx][sy] = 0;
    int xx[]{-1,0,1,0};
    int yy[]{0,1,0,-1};
    while(!Q.empty()){
        int x{Q.front().first};
        int y{Q.front().second};
        Q.pop();
        if(board[x][y] >= 2){
            dist[1][board[x][y]] = ch[x][y];
        }
        for(int dir{0}; dir < 4; ++dir){
            int nx{x + xx[dir]};
            int ny{y + yy[dir]};
            if(nx < 0 || nx > n - 1 || ny < 0 || ny > n - 1) continue;
            if(board[nx][ny] == -1) continue;
            if(ch[nx][ny] == -1){
                ch[nx][ny] = ch[x][y] + 1;
                Q.push({nx, ny});
            }
        }
    }
    for(auto& i : A){
        Q.push({i.first, i.second});
        vector<vi> ch(n, vi(n, -1));
        ch[i.first][i.second] = 0;
        while(!Q.empty()){
            int x{Q.front().first};
            int y{Q.front().second};
            Q.pop();
            if(board[x][y] >= 1){
                dist[board[i.first][i.second]][board[x][y]] = ch[x][y];
                dist[board[x][y]][board[i.first][i.second]] = ch[x][y];
            }
            for(int dir{0}; dir < 4; ++dir){
                int nx{x + xx[dir]};
                int ny{y + yy[dir]};
                if(nx < 0 || nx > n - 1 || ny < 0 || ny > n - 1) continue;
                if(board[nx][ny] == -1) continue;
                if(ch[nx][ny] == -1){
                    ch[nx][ny] = ch[x][y] + 1;
                    Q.push({nx, ny});
                }
            }
        }
    }
    vi p(k + 2);
    for(int i{1}; i <= k + 1; ++i){
        p[i] = i;
    }
    function<int(int)> find = [&](int a){
        if(a == p[a]) return a;
        return p[a] = find(p[a]);
    };
    function<bool(int,int)> merge = [&](int a, int b){
        a = find(a);
        b = find(b);
        if(a != b){
            p[a] = b;
            return true;
        }
        return false;
    };
    struct st{
        int a, b, w;
    };
    vector<st> edge;
    for(int i{1}; i <= k + 1; ++i){
        for(int j{i + 1}; j <= k + 1; ++j){
            edge.push_back({i, j, dist[i][j]});
        }
    }
    sort(edge.begin(), edge.end(), [&](st& x, st& y){
        return x.w < y.w;
    });
    int ans{0};
    int cnt2{0};
    for(auto& i : edge){
        if(i.w == -1) continue;
        if(merge(i.a, i.b)) {
            ans += i.w;
            cnt2++;
        }
    }
    if(cnt2 == k) cout << ans;
    else cout << -1;
}
