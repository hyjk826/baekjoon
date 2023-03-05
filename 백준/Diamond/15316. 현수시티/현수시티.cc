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

const int sz = 4e5 + 10;
vector<vp> g(sz);

struct st{
    vp A;
    int flag;
    pi p;
};

st tree[sz * 4];
int p[sz];
int depth[sz];
vp stk;
int ans[sz];

int find(int a){
    if(a == p[a]) return a;
    return find(p[a]);
}

void merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b){
        stk.push_back({-1, -1});
        return;
    }
    if(depth[a] > depth[b]) swap(a, b);
    p[a] = b;
    stk.push_back({a, b});
    if(depth[a] == depth[b]) depth[b]++;
}

void rev(){
    int a = stk.back().first;
    int b = stk.back().second;
    stk.pop_back();
    if(a == -1) return;
    p[a] = a;
    if(depth[b] == depth[a] + 1) depth[b]--;
}

void update1(int node, int l, int r, int idx, pi val){
    if(idx < l || idx > r) return;
    if(l == r){
        tree[node].flag = 1;
        tree[node].p = val;
        return;
    }   
    int m = (l + r) >> 1;
    update1(node << 1, l, m, idx, val);
    update1(node << 1 | 1, m + 1, r, idx, val);
}

void update2(int node, int l, int r, int s, int e, pi val){
    if(l > e || r < s) return;
    if(s <= l && r <= e){
        tree[node].A.push_back(val);
        return;
    }
    int m{(l + r) >> 1};
    update2(node << 1, l, m, s, e, val);
    update2(node << 1 | 1, m + 1, r, s, e, val);
}

void dfs(int node, int l, int r){
    for(int i{(int)tree[node].A.size() - 1}; i >= 0; --i){
        merge(tree[node].A[i].first, tree[node].A[i].second);
    }
    if(l == r){
        if(tree[node].flag){
            if(find(tree[node].p.first) == find(tree[node].p.second)) ans[l] = 1;
            else ans[l] = 0; 
        }
        for(int i{0}; i < (int)tree[node].A.size(); ++i) rev();
        return;
    }
    int m = (l + r) >> 1;
    dfs(node << 1, l, m);
    dfs(node << 1 | 1, m + 1, r);
    for(int i{0}; i < (int)tree[node].A.size(); ++i) rev();
}

int main(){
	fastio;
    int n, m;
    cin >> n >> m;
    memset(ans, -1, sizeof(ans));
    for(int i{1}; i <= n; ++i){
        p[i] = i;
    }
    struct query{
        int a, b, c;
    };
    vp edge(m);
    for(int i{0}; i < m; ++i){
        cin >> edge[i].first >> edge[i].second;
    }
    vi ch(m);
    vector<query> Q;
    for(int i{0}; i < m; ++i){
        int a;
        cin >> a;
        if(a){
            ch[i] = 1;
            Q.push_back({1, edge[i].first, edge[i].second});
        }
    }
    int q;
    cin >> q;
    while(q--){
        int op, a, b;
        cin >> op;
        if(op == 1){
            cin >> a;
            a--;
            if(ch[a]){
                Q.push_back({2, edge[a].first, edge[a].second});
            }
            else{
                Q.push_back({1, edge[a].first, edge[a].second});
            }
            ch[a] ^= 1;
        }
        else{
            cin >> a >> b;
            Q.push_back({3, a, b});
        }
    }
    for(int i{0}; i < (int)Q.size(); ++i){
        int a, b, c;
        a = Q[i].a; b = Q[i].b; c = Q[i].c;
        if(a == 1 || a == 2){
            if(b > c) swap(b, c);
            g[b].push_back({c, i});
        }
        else{
            update1(1, 0, Q.size() - 1, i, {b, c});
        }
    }
    for(int i{1}; i <= n; ++i){
        sort(g[i].begin(), g[i].end());
        for(int j{0}; j < (int)g[i].size(); ++j){
            if(j == (int)g[i].size() - 1 || g[i][j].first != g[i][j + 1].first){
                update2(1, 0, Q.size() - 1, g[i][j].second, Q.size() - 1, {i, g[i][j].first});
            }
            else{
                update2(1, 0, Q.size() - 1, g[i][j].second, g[i][j + 1].second, {i, g[i][j].first});
                j++;
            }
        }
    }
    dfs(1, 0, Q.size() - 1);
    for(int i{0}; i < Q.size(); ++i){
        if(ans[i] != -1){
            if(ans[i]) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}
