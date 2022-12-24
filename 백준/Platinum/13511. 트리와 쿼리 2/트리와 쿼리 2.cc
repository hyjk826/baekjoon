// 2022-12-24
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

int n;
int root = 1;
int sz = (int)1e5 + 1;
vector<vp> g(sz);
vi depth(sz, -1);
vector<vi> par(sz, vi(20, -1));

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
}

int LCA(int a, int b){
    if(depth[a] < depth[b]) swap(a, b);
    int dif = depth[a] - depth[b];
    for(int i{0}; dif > 0; ++i){
        if(dif & 1) a = par[a][i];
        dif >>= 1;
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

int dist(int u, int v){
    return depth[u] + depth[v] - 2 * depth[LCA(u, v)];
}

int p(int a, int b){
    for(int i{0}; b > 0; ++i){
        if(b & 1) a = par[a][i];
        b >>= 1;
    }
    return a;
}

int main(){
	fastio;
    cin >> n;
    for(int i{0}; i < n - 1; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    bfs();
    vl d(n + 1, -1);
    queue<int> Q;
    Q.push(1);
    d[1] = 0;
    while(!Q.empty()){
        int x{Q.front()};
        Q.pop();
        for(auto& i : g[x]){
            if(d[i.first] == -1){
                d[i.first] = d[x] + i.second;
                Q.push(i.first);
            }
        }
    }
    int q;
    cin >> q;
    while(q--){
        int a, b, c, k;
        cin >> a;
        if(a == 1){
            cin >> b >> c;
            cout << d[b] + d[c] - 2 * d[LCA(b, c)] << "\n";
        }
        else{
            cin >> b >> c >> k;
            int lca = LCA(b, c);
            if(k <= dist(b, lca) + 1) cout << p(b, k - 1) << "\n";
            else cout << p(c, dist(b, c) - k + 1) << "\n";
        }
    }
}
