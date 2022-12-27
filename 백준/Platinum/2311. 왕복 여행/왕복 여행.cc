#include <cstdio>

#include <queue>

#include <algorithm>

#include <vector>

#include <cstring>

using namespace std;

#define MAX 2006

int N, M;

vector<int> adj[MAX];

int C[MAX][MAX], f[MAX][MAX], d[MAX][MAX];

bool inQ[MAX];

int par[MAX];

int dist[MAX];

int src, sink;

void add_edge(int u, int v, int c, int dd) {

    adj[u].push_back(v);

    adj[v].push_back(u);

    C[u][v] = c;

    d[u][v] = dd;

    d[v][u] = -dd;

}

int mcmf() {

    int ret = 0;

    while (1) {

        memset(inQ, false, sizeof inQ);

        memset(par, -1, sizeof par);

        memset(dist, 0x3f, sizeof dist);

        queue<int> q;


        inQ[src] = true;

        dist[src] = 0;

        q.push(src);

        while (!q.empty()) {

            int here = q.front();

            q.pop();

            inQ[here] = false;

            for (int next : adj[here]) {

                if (C[here][next] - f[here][next] > 0 && dist[next] > dist[here] + d[here][next]) {

                    dist[next] = dist[here] + d[here][next];

                    par[next] = here;

                    if (!inQ[next]) {

                        inQ[next] = true;

                        q.push(next);

                    }

                }

            }

        }

        if (par[sink] == -1) break;

        int flow = 0x3f3f3f3f;

        for (int i = sink;i != src;i = par[i])

            flow = min(flow, C[par[i]][i] - f[par[i]][i]);

        for (int i = sink;i != src;i = par[i])

            f[par[i]][i] += flow, f[i][par[i]] -= flow, ret += (flow*d[par[i]][i]);

    }

    return ret;

}

int main() {

    scanf("%d%d", &N, &M);

    src = 0, sink = 2 * N - 1;

    for (int n = 1;n <= N;n++)

        add_edge(2 * n - 2, 2 * n - 1, 2, 0);

    for (int m = 0;m < M;m++) { 

        int u, v, dd;

        scanf("%d%d%d", &u, &v, &dd);

        add_edge(2 * u - 1, 2 * v - 2, 1, dd);

        add_edge(2 * v - 1, 2 * u - 2, 1, dd);

    }

    printf("%d\n", mcmf());

    return 0;    

}
