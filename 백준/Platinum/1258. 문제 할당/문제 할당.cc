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

#define MX 203
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

void solve(){
    int n;
    cin >> n;
    int source = MX - 1;
    int sink = MX - 2;
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < n; ++j){
            int a;
            cin >> a;            
            addEdge(i, j + n, 1, a);
        }
    }
    for(int j{0}; j < n; ++j){
        addEdge(source, j, 1, 0);
        addEdge(j + n, sink, 1, 0);
    }
    auto ret = MCMF(source, sink);
    cout << ret.second;
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
