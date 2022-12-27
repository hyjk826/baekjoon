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

#define MX 305
vi g[MX];
int capacity[MX][MX]{};
int flow[MX][MX]{};
int level[MX];
int work[MX];
int source = 0;
int sink = MX - 1;

void addEdge(int a, int b, int c){
    g[a].push_back(b);
    g[b].push_back(a);
    capacity[a][b] += c;
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
            if(level[i] == -1 && capacity[x][i] - flow[x][i] > 0){
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
        if(level[nx] == level[cur] + 1 && capacity[cur][nx] - flow[cur][nx] > 0){
            int f = dfs(nx, min(total, capacity[cur][nx] - flow[cur][nx]));
            if(f){
                flow[cur][nx] += f;
                flow[nx][cur] -= f;
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

int main(){
	fastio;
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        for(int i{0}; i <= n; ++i){
            g[i].clear();
            for(int j{0}; j <= n; ++j){
                capacity[i][j] = flow[i][j] = 0;
            }
        }
        source = 1;
        sink = n;
        vp edge;
        for(int i{0}; i < m; ++i){
            int a, b, c;
            cin >> a >> b >> c;
            addEdge(a, b, c);
            edge.push_back({a, b});
        }
        int ans{0};
        dinik();
        for(auto& i : edge){
            int a = i.first;
            int b = i.second;
            if(capacity[a][b] != flow[a][b]) continue;
            vi par(MX, -1);
            queue<int> Q;
            Q.push(a);
            while(!Q.empty()){
                int x{Q.front()};
                Q.pop();
                for(auto& j : g[x]){
                    if(par[j] == -1 && capacity[x][j] - flow[x][j] > 0){
                        par[j] = x;
                        Q.push(j);
                    }
                }
            }
            if(par[b] == -1) ans++;
        }
        cout << ans << "\n";
    }
}
