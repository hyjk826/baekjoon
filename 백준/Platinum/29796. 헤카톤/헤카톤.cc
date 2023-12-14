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

const int sz = 205;
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

void solve(){
	int n, m;
    cin >> n >> m;
    vi vec(n + 1);
    for(int i{1}; i <= n; ++i) cin >> vec[i];
    for(int i{0}; i < m; ++i){
        int a, b;
        cin >> a >> b;
        addEdge(a, b + 100, (int)1e9);
        addEdge(b, a + 100, (int)1e9);
    }
    for(int i{1}; i <= n; ++i){
        addEdge(source, i, vec[i]);
        addEdge(i, i + 100, (int)1e9);
    }
    int k;
    cin >> k;
    vi A(k);
    for(int i{0}; i < k; ++i){
        int a;
        cin >> a;
        addEdge(a + 100, sink, 0);
        A[i] = a;
    }
    int l{0}, r{(int)1e7};
    int ans{-1};
    while(l <= r){
        int mid{(l + r) >> 1};
        for(int i{0}; i < sz; ++i){
            for(int j{0}; j < sz; ++j){
                flow[i][j] = 0;
            }
        }
        for(auto& i : A){
            capacity[i + 100][sink] = mid;            
        }
        int f = dinik();
        if(f == k * mid){
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    cout << ans << "\n";
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
