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

struct st{
    int l, r, flag, idx;
};

int n, q;
const int sz = 1e5 + 1;
vector<st> query(sz);

vi g[sz];
vi depth(sz, -1);
vector<vi> par(sz, vi(20, -1));
int root = 1;
vi in(sz), out(sz);
vi A;
vi vec(sz);
vi cnt(sz);
vi cnt2(1e6 + 1);
int sum{0};

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

int pv{0};

void dfs(int cur, int pre){
    A.push_back(cur);
    in[cur] = pv++;
    for(auto& i : g[cur]){
        if(i == pre) continue;
        dfs(i, cur);
    }
    A.push_back(cur);
    out[cur] = pv++;
}

void Plus(int k){
    cnt[A[k]]++;
    if(cnt[A[k]] == 1){
        cnt2[vec[A[k]]]++;
        if(cnt2[vec[A[k]]] == 1) sum++;
    }
    else{
        cnt2[vec[A[k]]]--;
        if(cnt2[vec[A[k]]] == 0) sum--;
    }
}

void Minus(int k){
    cnt[A[k]]--;
    if(cnt[A[k]] == 1){
        cnt2[vec[A[k]]]++;
        if(cnt2[vec[A[k]]] == 1) sum++;
    }
    else {
        cnt2[vec[A[k]]]--;
        if(cnt2[vec[A[k]]] == 0) sum--;
    }
}

int f(st& q){
    if(q.flag == 0){
        return sum;
    }
    else{
        int lca = LCA(A[q.l], A[q.r]);
        if(cnt2[vec[lca]] == 0) return sum + 1;
        else return sum;
    }
}

int main() {
	fastio;	
    cin >> n;
    for(int i{1}; i <= n; ++i){
        cin >> vec[i];
    }
    for(int i{0}; i < n - 1; ++i){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    bfs();
    dfs(1, -1);
    cin >> q;
    for(int i{0}; i < q; ++i){
        int a, b;
        cin >> a >> b;
        int lca = LCA(a, b);
        if(lca == a || lca == b) {
            if(in[a] > in[b]) swap(a, b);
            query[i].l = in[a];
            query[i].r = in[b];
            query[i].flag = 0;
        }
        else{
            if(in[a] > in[b]) swap(a, b);
            query[i].l = out[a];
            query[i].r = in[b];
            query[i].flag = 1;
        }
        query[i].idx = i;
    }
    int sq = sqrt(n);
    sort(query.begin(), query.begin() + q, [&](st& a, st& b){
        if(a.l / sq == b.l / sq) return a.r < b.r;
        else return a.l / sq < b.l / sq;
    });
    int l = query[0].l;
    int r = query[0].r;
    vi ans(q);
    for(int i{l}; i <= r; ++i){
        Plus(i);
    }
    ans[query[0].idx] = f(query[0]);
    for(int i{1}; i < q; ++i){
        while(l > query[i].l) Plus(--l);
        while(r < query[i].r) Plus(++r);
        while(l < query[i].l) Minus(l++);        
        while(r > query[i].r) Minus(r--);
        ans[query[i].idx] = f(query[i]);
    }
    for(auto& i : ans) cout << i << "\n";
}
	
