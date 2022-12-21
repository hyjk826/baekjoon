// 2022-12-21
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

vi uni(1001);

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

struct st{
    int a, b, w;
};

vp g[1001];
vi depth(1001, -1);
vector<vi> par(1001, vi(20, -1));
vector<vi> mn(1001, vi(20));
vector<vi> mx(1001, vi(20));
int root;
int n;

void bfs()
{
    depth[root] = 0;
    queue<int> Q;
    Q.push(root);
    while (!Q.empty())
    {
        int x{Q.front()};
        Q.pop();
        for (auto& i : g[x])
        {
            if (depth[i.first] == -1)
            {
                depth[i.first] = depth[x] + 1;
                par[i.first][0] = x;
                mn[i.first][0] = i.second;
                mx[i.first][0] = i.second;
                Q.push(i.first);
            }
        }
    }
    for (int i{1}; i < 20; ++i)
    {
        for (int j{1}; j <= n; ++j)
        {
            if (par[j][i - 1] == -1)
                continue;
            par[j][i] = par[par[j][i - 1]][i - 1];
            mn[j][i] = min(mn[par[j][i - 1]][i - 1], mn[j][i - 1]);
            mx[j][i] = max(mx[par[j][i - 1]][i - 1], mx[j][i - 1]);
        }
    }
}

pi maxMinRoad(int a, int b)
{
    pi r = {MAX, 0};
    if (depth[a] < depth[b])
        swap(a, b);
    int dif = depth[a] - depth[b];
    for (int i{0}; dif > 0; ++i)
    {
        if (dif & 1)
        {
            r.first = min(r.first, mn[a][i]);
            r.second = max(r.second, mx[a][i]);
            a = par[a][i];
        }
        dif >>= 1;
    }
    if (a != b)
    {
        for (int i{19}; i >= 0; --i)
        {
            if (par[a][i] != -1 && par[a][i] != par[b][i])
            {
                r.first = min(r.first, mn[a][i]);
                r.first = min(r.first, mn[b][i]);
                r.second = max(r.second, mx[a][i]);
                r.second = max(r.second, mx[b][i]);
                a = par[a][i];
                b = par[b][i];
            }
        }
        r.first = min(r.first, mn[a][0]);
        r.first = min(r.first, mn[b][0]);
        r.second = max(r.second, mx[a][0]);
        r.second = max(r.second, mx[b][0]);
    }
    return r;
}

// 1 - 2 - 3 - 4

int main(){
	fastio;
    int m;
    cin >> n >> m;
    vector<st> edge(m);
    for(int i{0}; i < m; ++i){
        cin >> edge[i].a >> edge[i].b >> edge[i].w;
    }
    sort(edge.begin(), edge.end(), [&](st& a, st& b){
        return a.w < b.w;
    });
    int q;
    cin >> q;
    int sum{0};
    for(int i{1}; i <= n; ++i){
        uni[i] = i;
    }
    for(int i{0}; i < m; ++i){
        if(Union(edge[i].a, edge[i].b)){
            g[edge[i].a].push_back({edge[i].b, edge[i].w});
            g[edge[i].b].push_back({edge[i].a, edge[i].w});
            sum += edge[i].w;
        }
    }
    root = 1;
    bfs();
    while(q--){
        int a, b;
        cin >> a >> b;
        cout << sum - maxMinRoad(a, b).second << "\n";
    }
}
	
