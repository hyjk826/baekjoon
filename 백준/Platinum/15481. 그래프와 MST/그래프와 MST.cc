// 2023-01-04
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

vi uni(200001);
vector<vp> g(200001);
vi depth(200001, -1);
vector<vi> par(200001, vi(20, -1));
vector<vi> mx(200001, vi(20));
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

int main(){
	fastio;
    cin >> n >> m;
    vector<st> edge(m);
    for(int i{0}; i < m; ++i){
        cin >> edge[i].a >> edge[i].b >> edge[i].w;
    }
    auto temp = edge;
    sort(temp.begin(), temp.end(), [&](st x, st y){
        return x.w < y.w;
    });
    for(int i{1}; i <= n; ++i){
        uni[i] = i;
    }
    ll sum{0};
    for(int i{0}; i < m; ++i){
        int a = temp[i].a;
        int b = temp[i].b;
        if(Union(a, b)){
            sum += temp[i].w;
            g[a].push_back({b, temp[i].w});
            g[b].push_back({a, temp[i].w});
        }
    }
    bfs();
    for(int i{0}; i < m; ++i){
        cout << sum - maxRoad(edge[i].a, edge[i].b) + edge[i].w << '\n';
    }

}
