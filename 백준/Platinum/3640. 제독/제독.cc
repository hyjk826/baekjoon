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

#define MX 2005
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
	
void init(){
    for(int i{0}; i < MX; ++i){
        g[i].clear();
        for(int j{0}; j < MX; ++j){
            capacity[i][j] = flow[i][j] = d[i][j] = 0;
        }
    }
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
    while(cin >> n >> m){
        init();
        source = in(1);
        sink = out(n);
        for(int i{0}; i < m; ++i){
            int a, b, c;
            cin >> a >> b >> c;
            addEdge(out(a), in(b), 1, c);
        }
        for(int i{2}; i <= n - 1; ++i){
            addEdge(in(i), out(i), 1, 0);
        }
        addEdge(in(1), out(1), 2, 0);
        addEdge(in(n), out(n), 2, 0);
        cout << MCMF().second << "\n";
    }
}
