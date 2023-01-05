// 2023-01-05
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
vector<vp> mx(200001, vp(20, {-1, -1}));
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
                mx[i.first][0].first = i.second;
                Q.push(i.first);
            }
        }
    }
    function<pi(pi, pi)> update = [&](pi A, pi B){
        vi ret;
        ret.push_back(A.first);
        ret.push_back(A.second);
        ret.push_back(B.first);
        ret.push_back(B.second);
        sort(ret.begin(), ret.end());
        ret.erase(unique(ret.begin(), ret.end()), ret.end());
        pi r = {-1,-1};
        r.first = ret.back();
        if(ret.size() >= 2){
            r.second = ret[(int)ret.size() - 2];
        }
        return r;
    };
    for (int i{ 1 }; i < 20; ++i) {
        for (int j{ 1 }; j <= n; ++j) {
            if (par[j][i - 1] == -1) continue;            
            par[j][i] = par[par[j][i - 1]][i - 1];
            // mx[j][i] = max(mx[par[j][i - 1]][i - 1], mx[j][i - 1]);
            mx[j][i] = update(mx[par[j][i - 1]][i - 1], mx[j][i - 1]);
        }
    }
}

vi maxRoad(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);
    int dif = depth[a] - depth[b];
    vi ret = {-1,-1};
    function<void(pi)> update = [&](pi k){
        ret.push_back(k.first);
        ret.push_back(k.second);
        sort(ret.begin(), ret.end());
        ret.erase(unique(ret.begin(), ret.end()), ret.end());
        reverse(ret.begin(), ret.end());
        if(ret.size() > 2){
            ret.resize(2);
        }
    };
    for (int i{ 0 }; dif > 0; ++i) {
        if (dif & 1) {
            update(mx[a][i]);
            a = par[a][i];
        }
        dif >>= 1;
    }
    if (a != b) {
        for (int i{ 19 }; i >= 0; --i) {
            if (par[a][i] != -1 && par[a][i] != par[b][i]) {
                update(mx[a][i]);
                update(mx[b][i]);
                a = par[a][i];
                b = par[b][i];
            }
        }
        update(mx[a][0]);
        update(mx[b][0]);
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
    sort(edge.begin(), edge.end(), [&](st x, st y){
        return x.w < y.w;
    });
    for(int i{1}; i <= n; ++i){
        uni[i] = i;
    }
    int cnt{0};
    ll sum{0};
    vector<st> r;
    for(int i{0}; i < m; ++i){
        int a = edge[i].a;
        int b = edge[i].b;
        if(Union(a, b)){
            sum += edge[i].w;
            g[a].push_back({b, edge[i].w});
            g[b].push_back({a, edge[i].w});
            cnt++;
        }
        else r.push_back(edge[i]);
    }
    if(cnt != n - 1){
        cout << -1;
        return 0;
    }
    bfs();
    ll ans{LLONG_MAX};
    for(auto& i : r){
        auto ret = maxRoad(i.a, i.b);
        if(ret[0] < i.w){
            ans = min(ans, sum - ret[0] + i.w);
        }
        else{
            if(ret[1] == -1) continue;
            ans = min(ans, sum - ret[1] + i.w);
        }
    }
    if(ans == LLONG_MAX) cout << -1;
    else cout << ans;
}
