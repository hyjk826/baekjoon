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
    int v, w;
    bool operator< (const st& a) const{
        return w > a.w;
    }
};

int main(){
	fastio;
    int n, m;
    cin >> n >> m;
    int s, e, k, y;
    cin >> s >> e >> k >> y;
    vi path(y);
    for(int i{0}; i < y; ++i){
        cin >> path[i];
    }
    vector<vp> g(n + 1);
    unordered_map<int, unordered_map<int, int> > edge;
    for(int i{0}; i < m; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        edge[min(a, b)][max(a, b)] = c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    int sum{-k};
    unordered_map<int, unordered_map<int,pi> > block;
    for(int i{0}; i < y - 1; ++i){
        int a = edge[min(path[i], path[i + 1])][max(path[i], path[i + 1])];
        block[min(path[i], path[i + 1])][max(path[i], path[i + 1])] = {sum, sum + a};
        sum += a;
    }
    vi dijk(n + 1, MAX);
    dijk[s] = 0;
    priority_queue<st> pQ;
    pQ.push({s, 0});
    while(!pQ.empty()){
        int v{pQ.top().v};
        int w{pQ.top().w};
        pQ.pop();
        if(dijk[v] < w) continue;
        for(auto& i : g[v]){
            int x = min(v, i.first);
            int y = max(v, i.first);
            int nv{i.first};
            int nw{w + i.second};
            if(block.count(x) && block[x].count(y) && block[x][y].first <= w && w < block[x][y].second) nw = block[x][y].second + i.second;
            if(dijk[nv] > nw){
                dijk[nv] = nw;
                pQ.push({nv, nw});
            }
        }
    }
    cout << dijk[e];
}
