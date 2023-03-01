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

const int sz = 3e5 + 10;
vector<vp> g(sz);
vi depth(sz, -1);
vector<vi> par(sz, vi(20, -1));
vector<vi> mx(sz, vi(20));
int root = 1;
int n, m;

void bfs() {
    depth[root] = 0;
    queue<int> Q;
    Q.push(root);
    while (!Q.empty()) {
        int x{ Q.front() };
        Q.pop();
        for (auto& i : g[x]) {
            if (depth[i.first] == -1) {
                depth[i.first] = depth[x] + 1;
                par[i.first][0] = x;
                mx[i.first][0] = i.second;
                Q.push(i.first);
            }
        }
    }
    for (int i{ 1 }; i < 20; ++i) {
        for (int j{ 1 }; j <= n; ++j) {
            if (par[j][i - 1] == -1) continue;            
            par[j][i] = par[par[j][i - 1]][i - 1];
            mx[j][i] = max(mx[par[j][i - 1]][i - 1], mx[j][i - 1]);
        }
    }
}

int maxRoad(int a, int b) {
    int ret = 0;
    if (depth[a] < depth[b]) swap(a, b);
    int dif = depth[a] - depth[b];
    for (int i{ 0 }; dif > 0; ++i) {
        if (dif & 1) {
            ret = max(ret, mx[a][i]);
            a = par[a][i];
        }
        dif >>= 1;
    }
    if (a != b) {
        for (int i{ 19 }; i >= 0; --i) {
            if (par[a][i] != -1 && par[a][i] != par[b][i]) {
                ret = max(ret, mx[a][i]);
                ret = max(ret, mx[b][i]);                
                a = par[a][i];
                b = par[b][i];
            }
        }
        ret = max(ret, mx[a][0]);
        ret = max(ret, mx[b][0]);
    }
    return ret;
}

vi maxSeg(sz * 4);
vi vec(sz);

void init(int node, int l, int r){
    if (l == r){
        maxSeg[node] = vec[l];
        return;
    }
    int m = (l + r) / 2;
    init(node * 2, l, m);
    init(node * 2 + 1, m + 1, r);
    maxSeg[node] = max(maxSeg[node * 2], maxSeg[node * 2 + 1]);
}

int query(int node, int l, int r, int s, int e)
{
    if (r < s || e < l)
        return 0;
    if (s <= l && r <= e)
        return maxSeg[node];
    int m = (l + r) / 2;
    int left = query(node * 2, l, m, s, e);
    int right = query(node * 2 + 1, m + 1, r, s, e);
    return max(left, right);
}

int main(){
	fastio;
    int q;
    cin >> n >> q;
    for(int i{0}; i < n - 1; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    bfs();
    for(int i{1}; i < n; ++i){
        vec[i] = maxRoad(i, i + 1);
    }
    init(1, 1, n);
    for(int i{0}; i < q; ++i){
        int a, b;
        cin >> a >> b;
        cout << query(1, 1, n, a, b - 1) << "\n";
    }
}
