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

const int sz = 3e4 + 10;
vi g[sz];
vi depth(sz, -1);
vector<vi> par(sz, vi(20, -1));
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
            if(depth[i] == -1){
                depth[i] = depth[x] + 1;
                par[i][0] = x;
                Q.push(i);
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

int main(){
	fastio;
    cin >> n;
    for(int i{0}; i < n - 1; ++i){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    bfs();
    vi path;
    path.push_back(1);
    int m;
    cin >> m;
    for(int i{0}; i < m; ++i){
        int a;
        cin >> a;
        path.push_back(a);
    }
    ll ans{0};
    for(int i{0}; i < (int)path.size() - 1; ++i){
        ans += dist(path[i], path[i + 1]);
    }
    cout << ans;
}
