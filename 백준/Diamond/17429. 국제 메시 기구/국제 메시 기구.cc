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
#define ll unsigned int
#define MAX 2147000000
using namespace std;

int sz = (int)5e5 + 10;
int n, q;

struct st {
	ll v, a, b;
    st() : a(1), b(0) {}
};

vector<st> seg(sz * 4);
vector<ll> vec(sz);

ll init(int node, int l, int r) {
	if (l == r) return seg[node].v = vec[l];
	int m{ (l + r) / 2 };
	return seg[node].v = init(node * 2, l, m) + init(node * 2 + 1, m + 1, r);
}

void propogate(int node, int l, int r){
    if(seg[node].a == 1 && seg[node].b == 0) return;
    if(l != r){
        seg[node * 2].a = (seg[node * 2].a * seg[node].a);
        seg[node * 2 + 1].a = (seg[node * 2 + 1].a * seg[node].a);
        seg[node * 2].b = (seg[node].a * seg[node * 2].b + seg[node].b);
        seg[node * 2 + 1].b = (seg[node].a * seg[node * 2 + 1].b + seg[node].b);
    }
    seg[node].v = (seg[node].a * seg[node].v + (r - l + 1) * seg[node].b);
    seg[node].a = 1;
    seg[node].b = 0;
}

void segUpdate(int node, int l, int r, int s, int e, ll mul, ll add) {
	propogate(node, l, r);
	if (e < l || r < s) return;
	if (s <= l && r <= e) {
		seg[node].a = mul;
        seg[node].b = add;
		propogate(node, l, r);
		return;
	}
	int m{ (l + r) / 2 };
	segUpdate(node * 2, l, m, s, e, mul, add);
	segUpdate(node * 2 + 1, m + 1, r, s, e, mul, add);
	seg[node].v = (seg[node * 2].v + seg[node * 2 + 1].v);
}

ll segQuery(int node, int l, int r, int s, int e) {
	propogate(node, l, r);
	if (e < l || r < s) return 0;
	if (s <= l && r <= e) return seg[node].v;
	int m{ (l + r) / 2 };
	return (segQuery(node * 2, l, m, s, e) + segQuery(node * 2 + 1, m + 1, r, s, e));
}

vi sub(sz), depth(sz), par(sz), top(sz), in(sz), out(sz);

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
    out[cur] = pv;
}

void update(int a, int b, int mul, int add){
    while(top[a] ^ top[b]){
        if(depth[top[a]] < depth[top[b]]) swap(a, b);
        int st = top[a];
        segUpdate(1, 1, n, in[st], in[a], mul, add);
        a = par[st];
    }
    if(depth[a] > depth[b]) swap(a, b);
    segUpdate(1, 1, n, in[a], in[b], mul, add);
}

ll query(int a, int b){
    ll ret = 0;
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

struct qr{
    int op, x, y, v;
};

int main(){
	fastio;
    cin >> n >> q;
    for(int i{0}; i < n - 1; ++i){
        int a, b;
        cin >> a >> b;
        tempg[a].push_back(b);
        tempg[b].push_back(a);
    }
    top[1] = 1;
    dfs0();
    dfs1();
    dfs2();
    vector<qr> Q(q);
    for(int i{0}; i < q; ++i){
        int op, x, y, v;
        cin >> op;
        if(op == 1){
            cin >> x >> v;
            segUpdate(1, 1, n, in[x], out[x], 1, v);
        }
        else if(op == 2){
            cin >> x >> y >> v;
            update(x, y, 1, v);
        }
        else if(op == 3){
            cin >> x >> v;
            segUpdate(1, 1, n, in[x], out[x], v, 0);
        }
        else if(op == 4){
            cin >> x >> y >> v;
            update(x, y, v, 0);
        }
        else if(op == 5){
            cin >> x;
            cout << segQuery(1, 1, n, in[x], out[x]) << "\n";
        }
        else if(op == 6){
            cin >> x >> y;
            cout << query(x, y) << "\n";
        }
    }
}
