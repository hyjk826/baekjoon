// 2022-12-24
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

vi g[505];
int capacity[505][505];
int flow[505][505];
int level[505];
int work[505];
int source = 0;
int sink = 504;

void addEdge(int a, int b, int c){
    g[a].push_back(b);
    g[b].push_back(a);
    capacity[a][b] = c;
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
    for(int i{1}; i <= n; ++i){
        int a;
        cin >> a;
        if(a == 1) addEdge(source, i, MAX);
        else if(a == 2) addEdge(i, sink, MAX);
    }
    for(int i{1}; i <= n; ++i){
        for(int j{1}; j <= n; ++j){
            int a;
            cin >> a;
            if(i == j) continue;
            addEdge(i, j, a);
        }
    }
    cout << dinik() << "\n";
    queue<int> Q;
    Q.push(source);
    vi ch(n + 1);
    ch[source] = 1;
    while(!Q.empty()){
        int x{Q.front()};
        Q.pop();
        for(auto& i : g[x]){
            if(ch[i] == 0 && capacity[x][i] - flow[x][i] > 0){
                ch[i] = 1;
                Q.push(i);
            }
        }
    }
    for(int i{1}; i <= n; ++i){
        if(ch[i] == 1) cout << i << " ";
    }
    cout << "\n";
    for(int i{1}; i <= n; ++i){
        if(ch[i] == 0) cout << i << " ";
    }
    cout << "\n";
}
