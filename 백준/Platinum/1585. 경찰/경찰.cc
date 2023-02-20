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

#define MX 105
vector<vi> g(MX);
int capacity[MX][MX];
int flow[MX][MX];
int d[MX][MX];

void addEdge(int a, int b, int c, int dist){
    g[a].push_back(b);
    g[b].push_back(a);
    d[a][b] += dist;
    d[b][a] -= dist;
    capacity[a][b] += c;
}

pi MCMF(int source, int sink){
    int cost{0};
    int f{0};
    while(1){
        vi p(MX, -1);
        vi dist(MX, MAX);
        vi ch(MX);
        dist[source] = 0;
        ch[source] = 1;
        queue<int> Q;
        Q.push(source);
        while(!Q.empty()){
            int x{Q.front()};
            Q.pop();
            ch[x] = 0;
            for(auto& i : g[x]){
                if(capacity[x][i] - flow[x][i] > 0 && dist[i] > dist[x] + d[x][i]){
                    dist[i] = dist[x] + d[x][i];
                    p[i] = x;
                    if(!ch[i]){
                        Q.push(i);
                        ch[i] = 1;
                    }
                }
            }
        }
        if(p[sink] == -1) break;
        int ff = MAX;
        for(int i{sink}; i != source; i = p[i]){
            ff = min(ff, capacity[p[i]][i] - flow[p[i]][i]);
        }
        for(int i{sink}; i != source; i = p[i]){
            cost += ff * d[p[i]][i];
            flow[p[i]][i] += ff;
            flow[i][p[i]] -= ff;
        }
        f += ff;
    }
    return {f, cost};
}

int main(){
	fastio;
    int n;
    cin >> n;
    vi A(n), B(n);
    for(int i{0}; i < n; ++i){
        cin >> A[i];
    }
    for(int i{0}; i < n; ++i){
        cin >> B[i];
    }   
    int T, F;
    cin >> T >> F;
    int source = MX - 2;
    int sink = MX - 1;
    for(int i{0}; i < n; ++i){
        addEdge(source, i, 1, 0);
        for(int j{0}; j < n; ++j){
            if(B[j] > A[i]){
                int s = B[j] - A[i];
                if(T > s) addEdge(i, j + 50, 1, min(F, (T - s) * (T - s)));
                else addEdge(i, j + 50, 1, 0);
            }
        }
    }  
    for(int i{0}; i < n; ++i){
        addEdge(i + 50, sink, 1, 0);
    }
    auto ret = MCMF(source, sink);
    if(ret.first != n){
        cout << -1; return 0;
    }
    int mn = ret.second;
    for(int i{0}; i < MX; ++i){
        g[i].clear();
        for(int j{0}; j < MX; ++j){
            capacity[i][j] = flow[i][j] = d[i][j] = 0;
        }
    }
    for(int i{0}; i < n; ++i){
        addEdge(source, i, 1, 0);
        for(int j{0}; j < n; ++j){
            if(B[j] > A[i]){
                int s = B[j] - A[i];
                if(T > s) addEdge(i, j + 50, 1, -min(F, (T - s) * (T - s)));
                else addEdge(i, j + 50, 1, 0);
            }
        }
    }  
    for(int i{0}; i < n; ++i){
        addEdge(i + 50, sink, 1, 0);
    }
    int mx = MCMF(source, sink).second;
    cout << mn << " " << -mx;
}
