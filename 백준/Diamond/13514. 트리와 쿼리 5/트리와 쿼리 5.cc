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
#define MAX 1000000000
#define MOD 1000000007
using namespace std;

int n;
const int sz = (int)1e5 + 10;
vector<vi> g(sz);
vector<vi> centroid_tree(sz);
vi centroid_par(sz);
vi sub(sz);
vi ch(sz);
multiset<int> ms[sz];

vi depth(sz, -1);
vector<vi> par(sz, vi(20, -1));
int root = 1;

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

int getSub(int cur, int pre){
    sub[cur] = 1;
    for(auto& i : g[cur]){
        if(i == pre || ch[i]) continue;
        getSub(i, cur);
        sub[cur] += sub[i];
    }
    return sub[cur];
}

int getCent(int cur, int pre, int s){
    for(auto& i : g[cur]){
        if(i == pre || ch[i]) continue;
        if(sub[i] * 2 > s){
            return getCent(i, cur, s);
        }
    }
    return cur;
}

void buildCentroidTree(int cur, int pre = -1){
    int cent = getCent(cur, -1, getSub(cur, -1));
    if(pre != -1){
        centroid_tree[pre].push_back(cent);
        centroid_par[cent] = pre;
    }
    else centroid_par[cent] = cent;
    ch[cent] = 1;
    for(auto& i : g[cent]){
        if(ch[i]) continue;
        buildCentroidTree(i, cent);
    }
}

vi color(sz);

void update(int cur){
    int k = cur;
    color[cur] ^= 1;
    while(1){
        int d = dist(k, cur);
        if(color[cur]) ms[k].insert(d);
        else ms[k].erase(ms[k].find(d));
        if(k == centroid_par[k]) break;
        k = centroid_par[k];
    }
}

int query(int cur){
    int ret = MAX;
    int k = cur;
    while(1){
        int d = dist(k, cur);
        if(!ms[k].empty()) ret = min(ret, d + *ms[k].begin());
        if(k == centroid_par[k]) break;
        k = centroid_par[k];
    }
    if(ret == MAX) ret = -1;
    return ret;
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
    buildCentroidTree(1);
    bfs();
    int q;
    cin >> q;
    while(q--){
        int op, a;
        cin >> op >> a;
        if(op == 1) update(a);
        else cout << query(a) << "\n";
    }
}
