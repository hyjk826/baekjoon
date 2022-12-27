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

#define MX 405
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
	
struct st{
    int x1, y1, x2, y2, w;
};

int ccw(pl a, pl b, pl c){
    ll op = a.first * b.second + b.first * c.second + c.first * a.second;
    op -= (a.second * b.first + b.second * c.first + c.second * a.first);
    if(op > 0) return 1;
    else if(op == 0) return 0;
    else return -1;
}

bool isIntersect(pair<pl, pl> x, pair<pl, pl> y){
    pl a = x.first;
    pl b = x.second;
    pl c = y.first;
    pl d = y.second;
    int ab = ccw(a, b, c) * ccw(a, b, d);
    int cd = ccw(c, d, a) * ccw(c, d, b);
    if(ab == 0 && cd == 0){
        if(a > b) swap(a, b);
        if(c > d) swap(c, d);
        return c <= b && a <= d;
    }
    return ab <= 0 && cd <= 0;
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
        vector<st> A(n + 1);
        for(int i{1}; i <= n; ++i){
            cin >> A[i].x1 >> A[i].y1 >> A[i].x2 >> A[i].y2 >> A[i].w;
            addEdge(source, i, 1, 0);
        }
        vector<st> B(m + 1);
        for(int i{1}; i <= m; ++i){
            cin >> B[i].x1 >> B[i].y1 >> B[i].x2 >> B[i].y2 >> B[i].w;
            addEdge(200 + i, sink, 1, 0);
        }
        for(int i{1}; i <= n; ++i){
            for(int j{1}; j <= m; ++j){
                if(isIntersect({{A[i].x1, A[i].y1}, {A[i].x2, A[i].y2}}, {{B[j].x1, B[j].y1}, {B[j].x2, B[j].y2}})){ 
                    addEdge(i, 200 + j, 1, -A[i].w * B[j].w);
                }
            }
        }
        auto ans = MCMF();
        cout << ans.first << " " << -ans.second << "\n";
    }
}
