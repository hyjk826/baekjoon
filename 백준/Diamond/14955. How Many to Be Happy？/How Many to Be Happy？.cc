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

const int sz = 105;
vi g[sz];
int capacity[sz][sz]{};
int flow[sz][sz]{};
int level[sz];
int work[sz];
int source = 0;
int sink = sz - 1;
int p[sz];

struct st{
    int a, b, w;
};

void addEdge(int a, int b, int c){
    g[a].push_back(b);
    g[b].push_back(a);
    capacity[a][b] += c;
    capacity[b][a] += c;
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

int find(int a){
    if(a == p[a]) return a;
    else return p[a] = find(p[a]);
}

bool merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a != b){
        p[a] = b;
        return true;
    }
    return false;
}

int main(){
	fastio;
    int n, m;
    cin >> n >> m;
    vector<st> edge(m);
    for(int i{0}; i < m; ++i){
        cin >> edge[i].a >> edge[i].b >> edge[i].w;
    }
    ll ans{0};
    sort(edge.begin(), edge.end(), [&](st& x, st& y){
        return x.w < y.w;
    });
    int idx{0};
    for(int i{1}; i <= n; ++i){
        p[i] = i;
    }
    for(int i{0}; i < m; ++i){
        if(find(edge[i].a) != find(edge[i].b)){
            merge(edge[i].a, edge[i].b);
            continue;
        }
        for(int j{1}; j <= n; ++j){
            for(int k{1}; k <= n; ++k){
                flow[j][k] = 0;
            }
        }
        while(idx < m && edge[idx].w < edge[i].w){
            addEdge(edge[idx].a, edge[idx].b, 1);
            idx++;
        }
        source = edge[i].a;
        sink = edge[i].b;
        ans += dinik();
    }
    cout << ans;
}
