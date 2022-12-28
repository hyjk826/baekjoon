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

#define MX 2505
vector<vi> g(MX);
int capacity[MX][MX];
int flow[MX][MX];
int d[MX][MX];
int source = MX - 2;
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
    vector<vi> cost = {
        {10, 8, 7, 5, 1},
        {8, 6, 4, 3, 1},
        {7, 4, 3, 2, 1},
        {5, 3, 2, 2, 1},
        {1, 1, 1, 1, 0}
    };
    int n, m;
    cin >> n >> m;
    vector<vc> board(n, vc(m));
    int xx[]{-1,0,1,0};
    int yy[]{0,1,0,-1};
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            cin >> board[i][j];
        }
    }
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            if((i + j) & 1){
                for(int dir{0}; dir < 4; ++dir){
                    int nx{i + xx[dir]};
                    int ny{j + yy[dir]};
                    if(nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1) continue;
                    int a, b;
                    a = board[i][j] - 'A';
                    b = board[nx][ny] - 'A';
                    if(a == 5) a = 4;
                    if(b == 5) b = 4;
                    addEdge(i * m + j, nx * m + ny, 1, -cost[a][b]);
                }
                addEdge(source, i * m + j, 1, 0);
                addEdge(i * m + j, sink, 1, 0);
            }
            else{
                addEdge(i * m + j, sink, 1, 0);
            }
        }
    }
    cout << -MCMF().second;
}
