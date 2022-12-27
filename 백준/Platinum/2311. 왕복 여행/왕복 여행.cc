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

ll MCMF(){
	ll ret = 0;
	int inq[2020]; memset(inq, 0, sizeof inq);
	int par[2020]; memset(par, -1, sizeof par);
	int dst[2020]; memset(dst, 0x3f, sizeof dst);
	queue<int> q;
	q.push(source); inq[source] = 1; dst[source] = 0;
	while(q.size()){
		int now = q.front(); q.pop(); inq[now] = 0;
		for(auto nxt : g[now]){
			if(capacity[now][nxt] - flow[now][nxt] > 0 && dst[nxt] > dst[now] + d[now][nxt]){
				par[nxt] = now;
				dst[nxt] = dst[now] + d[now][nxt];
				if(!inq[nxt]){
					q.push(nxt); inq[nxt] = 1;
				}
			}
		}
	}
	for(int i=sink; i!=source; i=par[i]){
		ret += d[par[i]][i];
		flow[par[i]][i]++;
		flow[i][par[i]]--;
	}
	return ret;
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
    cin >> n >> m;
    source = out(1);
    sink = in(n);
    for(int i{0}; i < m; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        addEdge(out(a), in(b), 1, c);
        addEdge(out(b), in(a), 1, c);
    }
    for(int i{1}; i <= n; ++i){
        addEdge(in(i), out(i), MAX, 0);
    }
    cout << MCMF() + MCMF();
}
