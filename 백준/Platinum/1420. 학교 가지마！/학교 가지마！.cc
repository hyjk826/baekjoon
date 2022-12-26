// 2022-12-27
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

vi g[20100];
map<pi, int> capacity, flow;
int level[20100];
int work[20100];
int source;
int sink;

void addEdge(int a, int b, int c){
    g[a].push_back(b);
    g[b].push_back(a);
    capacity[{a, b}] = c;
}

bool bfs(){
    memset(level, -1, sizeof(level));
    queue<int> Q;
    level[source] = 0;
    Q.push(source);
    while(!Q.empty()){
        int x{Q.front()};
        Q.pop();
        for(auto& i : g[x]){
            if(level[i] == -1 && capacity[{x, i}] - flow[{x, i}] > 0){
                level[i] = level[x] + 1;
                Q.push(i);
            }
        }
    }
    return level[sink] != -1;
}

int dfs(int cur, int total){
    if(cur == sink) return total;
    for(int& i = work[cur]; i < (int)g[cur].size(); ++i){
        int nx = g[cur][i];
        if(level[nx] == level[cur] + 1 && capacity[{cur, nx}] - flow[{cur, nx}] > 0){
            int f = dfs(nx, min(total, capacity[{cur,nx}] - flow[{cur,nx}]));
            if(f){
                flow[{cur,nx}] += f;
                flow[{nx,cur}] -= f;
                return f;
            }
        }
    }
    return 0;
}

int dinik(){
    int ret{0};
    while(bfs()){
        memset(work, 0, sizeof(work));
        while(1){
            int f = dfs(source, MAX);
            if(f == 0) break;
            ret += f;
        }
    }
    return ret;
}

int in(int a){
    return (a << 1);
}

int out(int a){
    return (a << 1) | 1;
}
int main(){
	fastio;
    int n, m;
    cin >> n >> m;
    vector<vc> board(n, vc(m));
    int sx, sy, tx, ty;
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            cin >> board[i][j];
            if(board[i][j] == 'K'){
                sx = i; sy = j;
            }
            else if(board[i][j] == 'H'){
                tx = i; ty = j;
            }
        }
    }
    source = out(sx * m + sy);
    sink = in(tx * m + ty);
    int xx[]{-1,0,1,0};
    int yy[]{0,1,0,-1};
    for(int dir{0}; dir < 4; ++dir){
        int nx{sx + xx[dir]};
        int ny{sy + yy[dir]};
        if(nx == tx && ny == ty){
            cout << -1;
            return 0;
        }
    }
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            if(board[i][j] == '#') continue;
            for(int dir{0}; dir < 4; ++dir){
                int nx{i + xx[dir]};
                int ny{j + yy[dir]};
                if(nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1) continue;
                if(board[nx][ny] == '#') continue;
                addEdge(out(i * m + j), in(nx * m + ny), 1);
                addEdge(out(nx * m + ny), in(i * m + j), 1);
            }
            addEdge(in(i * m + j), out(i * m + j), 1);
        }
    }
    cout << dinik();
}
