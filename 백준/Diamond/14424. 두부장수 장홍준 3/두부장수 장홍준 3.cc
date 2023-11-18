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

#define x first
#define y second
typedef pair<int, int> p;

const int SZ = 40000 + 10;
struct MCMF{
	int s, t; //source, sink
	struct Edge{ int v, c, d, dual; };
	vector<Edge> g[SZ];
	void addEdge(int s, int e, int c, int d){
		g[s].push_back({e, c, d, (int)g[e].size()});
		g[e].push_back({s, 0, -d, (int)g[s].size()-1});
	}

	int h[SZ], inq[SZ]; //johnson's algorithm, spfa
	int dst[SZ]; //dijkstra
	void init(int _s, int _t){
		s = _s, t = _t;
        memset(h, 0x3f, sizeof h);
        memset(dst, 0x3f, sizeof dst);

		//johnson's algorithm with spfa
        queue<int> q; q.push(s); inq[s] = 1;
        while(q.size()){
            int now = q.front(); q.pop(); inq[now] = 0;
            for(auto i : g[now]){
                if(i.c && h[i.v] > h[now] + i.d){
                    h[i.v] = h[now] + i.d;
                    if(!inq[i.v]) inq[i.v] = 1, q.push(i.v);
                }
            }
        }
        for(int i=0; i<SZ; i++){
            for(auto &j : g[i]) if(j.c) j.d += h[i] - h[j.v];
        }

		//get shortest path DAG with dijkstra
        priority_queue<p> pq; pq.emplace(0, s); dst[s] = 0;
        while(pq.size()){
            int now = pq.top().y;
            int cst = -pq.top().x;
            pq.pop();
            if(dst[now] - cst) continue;
            for(auto i : g[now]){
                if(i.c && dst[i.v] > dst[now] + i.d){
                    dst[i.v] = dst[now] + i.d;
                    pq.emplace(-dst[i.v], i.v);
                }
            }
        }
        for(int i=0; i<SZ; i++) dst[i] += h[t] - h[s];
	}

	int chk[SZ], work[SZ];

	bool update(){ //update shortest path DAG in O(V+E)
		int mn = 1e9;
        for(int i=0; i<SZ; i++){
            if(!chk[i]) continue;
            for(auto j : g[i]){
                if(j.c && !chk[j.v]) mn = min(mn, dst[i] + j.d - dst[j.v]);
            }
        }
		if(mn >= 1e9) return 0;
		for(int i=0; i<SZ; i++){
			if(!chk[i]) dst[i] += mn;
		}
        return 1;
	}
	int dfs(int now, int fl){
        chk[now] = 1;
        if(now == t) return fl;
        for(; work[now] < g[now].size(); work[now]++){
            auto &i = g[now][work[now]];
            if(!chk[i.v] && dst[i.v] == dst[now] + i.d && i.c){
                int ret = dfs(i.v, min(fl, i.c));
                if(ret){
                    i.c -= ret; g[i.v][i.dual].c += ret;
                    return ret;
                }
            }
        }
        return 0;
	}
	p run(int _s, int _t){ //{cost, flow}
		init(_s, _t);
		int cst = 0, fl = 0;
		do{
			memset(chk, 0, sizeof chk);
            memset(work, 0, sizeof work);
			int now = 0;
			while(now = dfs(s, 1e9)){
				cst += dst[t] * now;
				fl += now;
				memset(chk, 0, sizeof chk);
			}
		}while(update());
		return p(cst, fl);
	}
} mcmf;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
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
    int source = SZ - 1;
    int sink = SZ - 2;
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
                    mcmf.addEdge(i * m + j, nx * m + ny, 1, -cost[a][b]);
                }
                mcmf.addEdge(source, i * m + j, 1, 0);
                mcmf.addEdge(i * m + j, sink, 1, 0);
            }
            else{
                mcmf.addEdge(i * m + j, sink, 1, 0);
            }
        }
    }
    cout << -mcmf.run(source, sink).first << "\n";
}