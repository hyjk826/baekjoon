// 2023-01-23
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

int sz = (int)3e4 + 10;
int n;

vi seg(sz * 4);

struct st{
    int op, a, b;
};

void segUpdate(int node, int l, int r, int idx, int value){
    if(l > idx || r < idx) return;
    if(l == r){
        seg[node] = value;
    }
    else{
        int m = (l + r) >> 1;
        segUpdate(node * 2, l, m, idx, value);
        segUpdate(node * 2 + 1, m + 1, r, idx, value);
        seg[node] = seg[node * 2] + seg[node * 2 + 1];
    }
}

int segQuery(int node, int l, int r, int s, int e){
    if (r < s || e < l) return 0;
    if (s <= l && r <= e) return seg[node];
    int m = (l + r) >> 1;
    return segQuery(node * 2, l, m, s, e) + segQuery(node * 2 + 1, m + 1, r, s, e);
}

vi sub(sz), depth(sz), par(sz), top(sz), in(sz);
vi uni(sz);
vector<vi> tempg(sz);
vector<vi> g(sz);

void dfs0(int cur = 1, int pre = -1){
    for(auto& i : tempg[cur]){
        if(i == pre) continue;
        g[cur].push_back(i);
        dfs0(i, cur);
    }
}

void dfs1(int cur = 1){
    sub[cur] = 1;
    for(auto& i : g[cur]){
        depth[i] = depth[cur] + 1;
        par[i] = cur;
        dfs1(i);
        sub[cur] += sub[i];
        if(sub[i] > sub[g[cur][0]]) swap(i, g[cur][0]);
    }
}

int pv{0};

void dfs2(int cur = 1){
    in[cur] = ++pv;
    for(auto& i : g[cur]){
        if(i == g[cur][0]){
            top[i] = top[cur];
        }
        else top[i] = i;
        dfs2(i);
    }
}

int query(int a, int b){
    int ret = 0;
    while(top[a] ^ top[b]){
        if(depth[top[a]] < depth[top[b]]) swap(a, b);
        int st = top[a];
        ret += segQuery(1, 1, n, in[st], in[a]);
        a = par[st];
    }
    if(depth[a] > depth[b]) swap(a, b);
    ret += segQuery(1, 1, n, in[a], in[b]);
    return ret;
}

int find(int a){
    if(a == uni[a]) return a;
    return uni[a] = find(uni[a]);
}

bool Union(int a, int b){
    a = find(a);
    b = find(b);
    if(a != b){
        uni[a] = b;
        return true;
    }
    return false;
}

int main(){
	fastio;
    cin >> n;
    vi penguin(n + 1);
    for(int i{1}; i <= n; ++i){
        cin >> penguin[i];
    }
    for(int i{1}; i <= n; ++i){
        uni[i] = i;
    }
    int q;
    cin >> q;
    vector<st> Q(q);
    for(int i{0}; i < q; ++i){
        string str;
        cin >> str;
        if(str == "bridge") Q[i].op = 0;
        else if(str == "penguins") Q[i].op = 1;
        else if(str == "excursion") Q[i].op = 2;
        cin >> Q[i].a >> Q[i].b;
    }
    int root;
    for(int i{0}; i < q; ++i){
        if(Q[i].op == 0){
            if(Union(Q[i].a, Q[i].b)){
                root = Q[i].a;
                tempg[Q[i].a].push_back(Q[i].b);
                tempg[Q[i].b].push_back(Q[i].a);
            }
        }
    }
    for(int i{1}; i <= n; ++i){
        uni[i] = i;
    }
    vi ch(n + 1);
    for(int i{1}; i <= n; ++i){
        if(ch[i]) continue;
        queue<int> Q;
        Q.push(i);
        ch[i] = 1;
        while(!Q.empty()){
            int x{Q.front()};
            Q.pop();            
            for(auto& j : tempg[x]){
                if(ch[j] == 0){
                    ch[j] = 1;
                    Q.push(j);
                }
            }
        }
        top[i] = i;
        dfs0(i);
        dfs1(i);
        dfs2(i);   
    }
    for(int i{1}; i <= n; ++i){
        segUpdate(1, 1, n, in[i], penguin[i]);
    }
    for(int i{0}; i < q; ++i){
        int op = Q[i].op;
        int a = Q[i].a;
        int b = Q[i].b;
        if(op == 0){
            if(Union(a, b)) cout << "yes\n";
            else cout << "no\n";
        }
        else if(op == 1){
            segUpdate(1, 1, n, in[a], b);
        }
        else if(op == 2){
            if(find(a) == find(b)){
                cout << query(a, b) << "\n";
            }
            else cout << "impossible\n";
        }
    }
}
