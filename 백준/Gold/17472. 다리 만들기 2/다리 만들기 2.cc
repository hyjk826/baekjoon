// 2022-07-12
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int n, m;

vi uni;

int find(int a){
    if(a == uni[a]) return a;
    return uni[a] = find(uni[a]);
}

bool Union(int a, int b){
    a = find(a);
    b = find(b);
    if(a != b){
        uni[a] = b;
        return true;
    }
    return false;
}

struct st{
    int a, b, dis;
};

int main() {
	fastio;
	cin >> n >> m;
    vector<vi> board(n, vi(m));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            cin >> board[i][j];
        }
    }
    int xx[]{-1,0,1,0};
    int yy[]{0,1,0,-1};
    int cnt{1};
    vector<vi> ch(n, vi(m));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            if(board[i][j] == 1){
                queue<pi> Q;
                Q.push({i, j});
                board[i][j] = 0;
                ch[i][j] = cnt;
                while(!Q.empty()){
                    int x{Q.front().first};
                    int y{Q.front().second};
                    Q.pop();
                    for(int dir{0}; dir < 4; ++dir){
                        int nx{x + xx[dir]};
                        int ny{y + yy[dir]};
                        if(nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1) continue;
                        if(board[nx][ny] == 1){
                            board[nx][ny] = 0;
                            ch[nx][ny] = cnt;
                            Q.push({nx, ny});
                        }
                    }
                }
                cnt++;
            }
        }
    }
    vector<vi> dis(cnt, vi(cnt, (int)1e8));
    uni.resize(cnt);
    for(int i{1}; i < cnt; ++i){
        uni[i] = i;
    }
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            if(ch[i][j] == 0) continue;
            for(int dir{0}; dir < 4; ++dir){
                int x = i;
                int y = j;
                while(1){
                    x += xx[dir];
                    y += yy[dir];
                    if(x < 0 || x > n - 1 || y < 0 || y > m - 1 || ch[x][y] == ch[i][j]) break;
                    if(ch[x][y] > 0){
                        if(abs(x - i) + abs(y - j) == 2) break;
                        dis[ch[i][j]][ch[x][y]] = min(dis[ch[i][j]][ch[x][y]], abs(x - i) + abs(y - j) - 1);
                        dis[ch[x][y]][ch[i][j]] = min(dis[ch[x][y]][ch[i][j]], abs(x - i) + abs(y - j) - 1);
                        break;
                    }
                }
            }
        }
    }
    vector<st> vec;
    for(int i{1}; i < cnt; ++i){
        for(int j{i + 1}; j < cnt; ++j){
            if(dis[i][j] == (int)1e8) continue;
            vec.push_back({i, j, dis[i][j]});
        }
    }
    int ans{0};
    int c{0};
    sort(vec.begin(), vec.end(), [&](st x, st y){
        return x.dis < y.dis;
    });
    for(int i{0}; i < (int)vec.size(); ++i){
        if(Union(vec[i].a, vec[i].b)){
            ans += vec[i].dis;
            c++;
        }
    }
    if(c == cnt - 2){
        cout << ans;
    }
    else cout << -1;
}
