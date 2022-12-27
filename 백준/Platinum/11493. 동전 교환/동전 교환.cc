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

#define MX 1005
vector<vi> g(MX);
int capacity[MX][MX];
int flow[MX][MX];
int d[MX][MX];
int source = 0;
int sink = MX - 1;

void addEdge(int a, int b, int c, int dist){
    g[a].push_back(b);
    g[b].push_back(a);
    capacity[a][b] += c;
    d[a][b] += dist;
    d[b][a] -= dist;
}

pi MCMF(){
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
    int t;
    cin >> t;
    while(t--){
        for(int i{0}; i < MX; ++i){
            g[i].clear();
            for(int j{0}; j < MX; ++j){
                capacity[i][j] = flow[i][j] = d[i][j] = 0;
            }
        }
        int n, m;
        cin >> n >> m;
        for(int i{0}; i < m; ++i){
            int a, b;
            cin >> a >> b;
            addEdge(a + 500, b, MAX, 1);
            addEdge(b + 500, a, MAX, 1);
        }
        vi A(n + 1), B(n + 1);
        for(int i{1}; i <= n; ++i){
            cin >> A[i];
        }
        for(int i{1}; i <= n; ++i){
            cin >> B[i];
        }
        for(int i{1}; i <= n; ++i){
            if(A[i] == B[i]) continue;
            if(A[i] == 0) addEdge(source, i, 1, 0);
            else addEdge(500 + i, sink, 1, 0);
        }
        for(int i{1}; i <= n; ++i){
            addEdge(i, 500 + i, MAX, 0);
        }
        cout << MCMF().second << "\n";
    }
}
