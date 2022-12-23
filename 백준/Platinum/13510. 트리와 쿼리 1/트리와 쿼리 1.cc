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

int sz = (int)1e5 + 10;
int n;

vi maxSeg(sz * 4);

struct st{
    int a, b, c;
};

vector<st> edge(sz);

void segUpdate(int node, int l, int r, int idx, int value){
    if(l > idx || r < idx) return;
    if(l == r){
        maxSeg[node] = value;
    }
    else{
        int m = (l + r) >> 1;
        segUpdate(node * 2, l, m, idx, value);
        segUpdate(node * 2 + 1, m + 1, r, idx, value);
        maxSeg[node] = max(maxSeg[node * 2], maxSeg[node * 2 + 1]);
    }
}

int segQuery(int node, int l, int r, int s, int e){
    if (r < s || e < l)
        return -MAX;
    if (s <= l && r <= e)
        return maxSeg[node];
    int m = (l + r) >> 1;
    int left = segQuery(node * 2, l, m, s, e);
    int right = segQuery(node * 2 + 1, m + 1, r, s, e);
    return max(left, right);
}

vi sub(sz), depth(sz), par(sz), top(sz), in(sz);

vector<vi> tempg(sz);
vector<vi> g(sz);

void dfs0(int cur, int pre){
    for(auto& i : tempg[cur]){
        if(i == pre) continue;
        g[cur].push_back(i);
        dfs0(i, cur);
    }
}

void dfs1(int cur){
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

void dfs2(int cur){
    in[cur] = ++pv;
    for(auto& i : g[cur]){
        if(i == g[cur][0]){
            top[i] = top[cur];
        }
        else top[i] = i;
        dfs2(i);
    }
}

void update(int idx, int k){
    edge[idx].c = k;
    if(par[edge[idx].a] == edge[idx].b) segUpdate(1, 1, n, in[edge[idx].a], k);
    else segUpdate(1, 1, n, in[edge[idx].b], k);
}



int query(int a, int b){
    int ret = -MAX;
    while(top[a] ^ top[b]){
        if(depth[top[a]] < depth[top[b]]) swap(a, b);
        int st = top[a];
        ret = max(ret, segQuery(1, 1, n, in[st], in[a]));
        a = par[st];
    }
    if(depth[a] > depth[b]) swap(a, b);
    ret = max(ret, segQuery(1, 1, n, in[a] + 1, in[b]));
    return ret;
}


int main(){
	fastio;
    cin >> n;
    for(int i{1}; i <= n - 1; ++i){
        cin >> edge[i].a >> edge[i].b >> edge[i].c;
        tempg[edge[i].a].push_back(edge[i].b);
        tempg[edge[i].b].push_back(edge[i].a);
    }
    dfs0(1, -1);
    dfs1(1);
    dfs2(1);
    for(int i{1}; i <= n - 1; ++i){
        update(i, edge[i].c);
    }
    int q;
    cin >> q;
    while(q--){
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 1){
            update(b, c);
        }
        else{
            cout << query(b, c) << "\n";
        }
    }
}
