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

vi g[305];
int capacity[305][305]{};
int flow[305][305]{};
int level[305];
int work[305];
int source = 0;
int sink = 301;

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
    int n, m;
    cin >> n >> m;
    vi A(n + 1), B(m + 1);
    for(int i{1}; i <= n; ++i){
        cin >> A[i];
    }
    for(int i{1}; i <= m; ++i){
        cin >> B[i];
    }
    for(int i{1}; i <= m; ++i){
        addEdge(source, i, B[i]);
    }
    for(int i{1}; i <= n; ++i){
        addEdge(100 + i, sink, A[i]);
    }
    for(int i{1}; i <= m; ++i){
        for(int j{1}; j <= n; ++j){
            int a;
            cin >> a;
            addEdge(i, 100 + j, a);
        }
    }
    cout << dinik();
}
