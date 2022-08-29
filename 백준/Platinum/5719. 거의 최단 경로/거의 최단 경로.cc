// 2022-08-29
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
#define ll long long
#define MAX 1000000000
#define MOD 1000000007
using namespace std;

struct st{
    int v, dis;
    bool operator< (const st& a) const{
        return dis > a.dis;
    }
};

int n, m, s, e;
vector<vector<st> > g(500);
vector<vi> dijkg(500);
set<pi> ss;

int dijk(){
    vi dijk(n + 1, MAX);
    dijk[s] = 0;
    priority_queue<st> pQ;
    pQ.push({s, 0});
    while(!pQ.empty()){
        int v{pQ.top().v};
        int dis{pQ.top().dis};
        pQ.pop();
        if(dijk[v] > dis) continue;
        for(auto& u : g[v]){
            int nv{u.v};
            int ndis{u.dis};
            if(ss.count({v, nv})) continue;
            if(dijk[nv] > dijk[v] + ndis){
                dijk[nv] = dijk[v] + ndis;
                pQ.push({nv, dijk[nv]});
                dijkg[nv].clear();
                dijkg[nv].push_back(v);
            }
            else if(dijk[nv] == dijk[v] + ndis){
                dijkg[nv].push_back(v);
            }
        }
    }
    return dijk[e];
}


int main() {
	fastio;
    while(1){
        cin >> n >> m;
        if(n == 0) break;
        cin >> s >> e;
        for(int i{0}; i < n; ++i){
            g[i].clear();
            dijkg[i].clear();
        }    
        ss.clear();
        for(int i{0}; i < m; ++i){
            int a, b, w;
            cin >> a >> b >> w;
            g[a].push_back({b, w});
        }
        dijk();
        queue<int> Q;
        Q.push(e);
        vi ch(n);
        ch[e] = 1;
        while(!Q.empty()){
            int v{Q.front()};
            Q.pop();
            for(auto& u : dijkg[v]){                
                ss.insert({u, v});
                if(ch[u] == 0){                                        
                    ch[u] = 1;
                    Q.push(u);
                }
            }
        }
        int r = dijk();
        if(r == MAX) cout << -1 << "\n";
        else cout << r << "\n";        
    }
}

