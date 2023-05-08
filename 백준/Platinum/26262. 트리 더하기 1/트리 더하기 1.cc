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

const int sz = 2e5 + 10;
vp g[sz];
vi depth(sz, -1);
vector<vi> par(sz, vi(20, -1));
vl dis(sz, -1);
int root = 1;
int n;

void bfs(){
    depth[root] = 0;
    queue<int> Q;
    Q.push(root);
    while(!Q.empty()){
        int x{Q.front()};
        Q.pop();
        for(auto& i: g[x]){
            if(depth[i.first] == -1){
                depth[i.first] = depth[x] + 1;
                par[i.first][0] = x;
                Q.push(i.first);
            }
        }
    }
    for(int i{1}; i < 20; ++i){
        for(int j{1}; j <= n; ++j){
            if(par[j][i - 1] == -1) continue;
            par[j][i] = par[par[j][i - 1]][i - 1];
        }
    }
    dis[root] = 0;
    Q.push(root);
    while(!Q.empty()){
        int x{Q.front()};
        Q.pop();
        for(auto& i : g[x]){
            if(dis[i.first] == -1){
                dis[i.first] = dis[x] + i.second;
                Q.push(i.first);
            }
        }
    }
}

int LCA(int a, int b){
    if(depth[a] < depth[b]) swap(a, b);
    int dif = depth[a] - depth[b];
    for(int i{0}; dif != 0; ++i){
        if(dif % 2 == 1) a = par[a][i];
        dif /= 2;
    }
    if(a != b){
        for(int i{19}; i >=0; --i){
            if(par[a][i] != -1 && par[a][i] != par[b][i]){
                a = par[a][i];
                b = par[b][i];
            }
        }
        a = par[a][0];
    }
    return a;
}

ll dist(int a, int b){
    return dis[a] + dis[b] - 2 * dis[LCA(a, b)];
}

int p[sz];

int find(int a){
    if(a == p[a]) return a;
    return p[a] = find(p[a]);
}

bool merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a != b){
        p[a] = b;
        return true;
    }
    return false;
}

int main(){
	fastio;
    cin >> n;
    iota(p + 1, p + n + 1, 1);
    int x, y, w;
    for(int i{0}; i < n; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        if(!merge(a, b)){
            x = a; y = b; w = c; continue;
        }
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    bfs();
    int q;
    cin >> q;
    while(q--){
        int u, v;
        cin >> u >> v;
        ll ans = dist(u, v);
        ans = min(ans, dist(u, x) + dist(y, v) + w);
        ans = min(ans, dist(u, y) + dist(x, v) + w);
        cout << ans << "\n";
    }
}
