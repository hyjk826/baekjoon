// 2022-12-08
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

vector<vi> g;
vector<vi> g2;
vi finished;
vi visited;
vi dp;
vi ch;
int cycle{0};

void dfs(int v){
    if(cycle) return;
    visited[v] = 1;
    for(auto& u : g[v]){
        if(visited[u] == 0){
            dfs(u);
        }
        else if(!finished[u]){
            cycle++;         
            return;   
        }
    }
    finished[v] = 1;
}

int f(int a){
    if(dp[a] != -1) return dp[a];
    int mx{0};
    for(auto& i : g2[a]){
        if(ch[i] == 0) continue;
        mx = max(mx, f(i));
    }
    return dp[a] = mx + 1;
}


int main() {
	fastio;
	int n, m;
    cin >> n >> m;
    vector<vc> board(n, vc(m));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            cin >> board[i][j];
        }
    }
    finished.resize(n * m);
    visited.resize(n * m);
    g.resize(n * m);
    g2.resize(n * m);
    dp.resize(n * m, -1);
    int xx[]{-1,0,1,0};
    int yy[]{0,1,0,-1};
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            if(board[i][j] == 'H') continue;
            int a = board[i][j] - '0';
            for(int dir{0}; dir < 4; ++dir){
                int nx{i + xx[dir] * a};
                int ny{j + yy[dir] * a};
                if(nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1 || board[nx][ny] == 'H') continue;
                g[i * m + j].push_back(nx * m + ny);
                g2[nx * m + ny].push_back(i * m + j);
            }
        }
    }
    dfs(0);
    if(cycle > 0) cout << -1;
    else{
        queue<int> Q;
        ch.resize(n * m);
        ch[0] = 1;
        Q.push(0);
        while(!Q.empty()){
            int x{Q.front()};
            Q.pop();
            for(auto& i : g[x]){
                if(ch[i] == 0){
                    ch[i] = 1;
                    Q.push(i);
                }
            }
        }
        int ans{0};
        dp[0] = 1;
        for(int i{0}; i < n * m; ++i){
            if(ch[i] == 0) continue;
            ans = max(ans, f(i));
        }
        cout << ans;
    }
}
	
