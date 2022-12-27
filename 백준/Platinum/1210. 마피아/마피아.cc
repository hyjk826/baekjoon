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

#define MX 405
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

int dfs(int cur, ll total){
    if(cur == sink) return total;
    for(int& i = work[cur]; i < (int)g[cur].size(); ++i){
        int nx = g[cur][i];
        if(level[nx] == level[cur] + 1 && capacity[cur][nx] - flow[cur][nx] > 0){
            int f = dfs(nx, min(total, (ll)capacity[cur][nx] - flow[cur][nx]));
            if(f){
                flow[cur][nx] += f;
                flow[nx][cur] -= f;
                return f;
            }
        }
    }
    return 0;
}

ll dinik(){
    ll ret{0};
    while(bfs()){
        memset(work, 0, sizeof(work));
        while(1){
            int f = dfs(source, (ll)1e15);
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
    int s, t;
    cin >> s >> t;
    source = in(s);
    sink = out(t);
    vi cost(n + 1);
    for(int i{1}; i <= n; ++i){
        cin >> cost[i];
        addEdge(in(i), out(i), cost[i]);
    }
    for(int i{0}; i < m; ++i){
        int a, b;
        cin >> a >> b;
        addEdge(out(a), in(b), MAX);
        addEdge(out(b), in(a), MAX);
    }
    dinik();
    queue<int> Q;
    Q.push(source);
    vi ch(MX);
    ch[source] = 1;
    while(!Q.empty()){
        int x{Q.front()};
        Q.pop();
        for(auto& i : g[x]){
            if(ch[i] == 0 && capacity[x][i] - flow[x][i] > 0){
                Q.push(i);
                ch[i] = 1;
            }
        }
    }
    for(int i{1}; i <= n; ++i){
        if(ch[in(i)] && !ch[out(i)]) cout << i << " ";
    }
}
