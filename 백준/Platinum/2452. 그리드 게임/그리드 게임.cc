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

void solve(){
	int n, m;
    cin >> n >> m;
    vector<vi> board(n, vi(m));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            cin >> board[i][j];
        }
    }
    vector<vi> ch(n, vi(m));
    set<pi> st;
    int a{1};
    int xx[]{-1,0,1,0};
    int yy[]{0,1,0,-1};
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            if(ch[i][j] == 0){
                ch[i][j] = a;
                queue<pi> Q;
                Q.push({i, j});
                while(!Q.empty()){
                    int x{Q.front().first};
                    int y{Q.front().second};
                    Q.pop();
                    for(int dir{0}; dir < 4; ++dir){
                        int nx{x + xx[dir]};
                        int ny{y + yy[dir]};
                        if(nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1) continue;
                        if(ch[nx][ny] == 0 && board[nx][ny] == board[x][y]){
                            ch[nx][ny] = a;
                            Q.push({nx, ny});
                        }
                    }
                }
                a++;
            }
        }
    }
    vector<vi> g(a);
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            for(int dir{0}; dir < 4; ++dir){
                int nx{i + xx[dir]};
                int ny{j + yy[dir]};
                if(nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1) continue;
                int a = ch[i][j];
                int b = ch[nx][ny];
                if(a != b && !st.count({min(a, b), max(a, b)})){
                    st.insert({min(a, b), max(a, b)});
                    g[a].push_back(b);
                    g[b].push_back(a);
                }
            }
        }
    }
    function<int(int)> bfs = [&](int start){
        queue<int> Q;
        Q.push(start);
        vi dist(a, -1);
        dist[start] = 0;
        while(!Q.empty()){
            int x{Q.front()};
            Q.pop();
            for(auto& i : g[x]){
                if(dist[i] == -1){
                    dist[i] = dist[x] + 1;
                    Q.push(i);
                }
            }
        }
        return *max_element(dist.begin(), dist.end());
    };
    int ans{MAX};
    for(int i{1}; i < a; ++i){
        ans = min(ans, bfs(i));
    }
    cout << ans;
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
