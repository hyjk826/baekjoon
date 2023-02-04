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

const int sz = 1e5 + 10;
vi g[sz];
vi depth(sz, -1);
vector<vi> par(sz, vi(20, -1));
int n;
vi A(sz);

void bfs(){
    depth[1] = 0;
    queue<int> Q;
    Q.push(1);
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

struct Node{
    ll v;
    Node* l, *r;
    Node(){
        l = r = NULL;
        v = 0;
    }
};

Node* root[201010];

void init(Node* node, int l, int r){
    if(l == r){
        node->v = 0;
        return;
    }
    int m = (l + r) >> 1;
    node->l = new Node();
    node->r = new Node();
    init(node->l, l, m);
    init(node->r, m + 1, r);
    node->v = node->l->v + node->r->v;
}

void update(Node* prev, Node* cur, int l, int r, int idx, int value){
    if(l == r){
        cur->v += value;
        return;
    }
    int m = (l + r) >> 1;
    if(cur->l == NULL) cur->l = prev->l;
    if(cur->r == NULL) cur->r = prev->r;
    if(idx <= m){
        if(cur->l == prev->l){
            cur->l = new Node();
            cur->l->v = prev->l->v;
        }
        update(prev->l, cur->l, l, m, idx, value);
    }
    else{
        if(cur->r == prev->r){
            cur->r = new Node();
            cur->r->v = prev->r->v;
        }
        update(prev->r, cur->r, m + 1, r, idx, value);
    }
    cur->v = cur->l->v + cur->r->v;
}

// Kth
int query(Node* a, Node* b, Node* c, Node* d, int l, int r, int k){
    if(l == r) return l;
    int diff = a->l->v + b->l->v - c->l->v - d->l->v;
    int m = (l + r) >> 1;
    if(k <= diff) return query(a->l, b->l, c->l, d->l, l, m, k);
    else return query(a->r, b->r, c->r, d->r, m + 1, r, k - diff);
}

int main(){
	fastio;
    cin >> n;
    for(int i{1}; i <= n; ++i){
        cin >> A[i];
    }
    for(int i{0}; i < n - 1; ++i){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    root[0] = new Node();
    init(root[0], 1, 1000000);
    function<void(int,int)> dfs = [&](int cur, int pre){
        root[cur] = new Node();
        update(root[pre], root[cur], 1, 1000000, A[cur], 1);
        for(auto& i : g[cur]){
            if(i == pre) continue;
            dfs(i, cur);
        }
    };
    par[1][0] = 0;
    dfs(1, 0);
    bfs();
    int q;
    cin >> q;
    while(q--){
        int a, b, c;
        cin >> a >> b >> c;
        int lca = LCA(a, b);
        cout << query(root[a], root[b], root[lca], root[par[lca][0]], 1, 1000000, c) << "\n";
    }
}
