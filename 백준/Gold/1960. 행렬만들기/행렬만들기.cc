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

const int sz = 1005;
vi g[sz];
int capacity[sz][sz]{};
int flow[sz][sz]{};
int level[sz];
int work[sz];
int source = sz - 2;
int sink = sz - 1;

void init(){
    for(int i{0}; i < sz; ++i){
        g[i].clear();
        for(int j{0}; j < sz; ++j){
            capacity[i][j] = flow[i][j] = 0;
        }
    }
}

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
    int n;
    cin >> n;
    for(int i{0}; i < n; ++i){
        int a;
        cin >> a;
        addEdge(source, i, a);
    }
    int sum{0};
    for(int i{0}; i < n; ++i){
        int a;
        cin >> a;
        sum += a;
        addEdge(i + 500, sink, a);
    }
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < n; ++j){
            addEdge(i, j + 500, 1);
        }
    }
    if(dinik() == sum){
        cout << 1 << "\n";
        for(int i{0}; i < n; ++i){
            for(int j{0}; j < n; ++j){
                cout << flow[i][j + 500];
            }
            cout << "\n";
        }
    }
    else cout << -1;
    
}
