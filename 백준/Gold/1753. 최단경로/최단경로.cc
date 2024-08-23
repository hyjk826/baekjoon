#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define vi vector<int> 
#define pi pair<int, int> 
#define vp vector<pi> 
#define MAX 2147000000
#define ll long long 
using namespace std; 

struct st{
    int v, w;
    bool operator< (const st& a) const{
        return w > a.w;
    }
};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, s;
    cin >> n >> m >> s;

    vector<vp> g(n + 1);
    for(int i{0}; i < m; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
    }

    priority_queue<st> pQ;

    pQ.push({s, 0});

    vi dist(n + 1, MAX);
    dist[s] = 0;

    while(!pQ.empty()){
        int v{pQ.top().v};
        int w{pQ.top().w};
        pQ.pop();
        if(dist[v] < w) continue;
        for(auto& i : g[v]){
            int nv{i.first};
            int nw{w + i.second};
            if(dist[nv] > nw){
                dist[nv] = nw;
                pQ.push({nv, nw});
            }
        }
    }

    for(int i{1}; i <= n; ++i){
        if(dist[i] == MAX) cout << "INF\n";
        else cout << dist[i] << "\n";
    }
}