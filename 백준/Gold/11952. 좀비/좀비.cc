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
    int v; ll w;
    bool operator< (const st& a) const{
        return w > a.w;
    }
};


int main(){
	fastio;
    int n, m, k, s;
    cin >> n >> m >> k >> s;
    int p, q;
    cin >> p >> q;
    vi ZOM(k);
    for(auto& a : ZOM){
        cin >> a;
    }
    vector<vi> g(n + 1);
    for(int i{0}; i < m; ++i){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vi dist(n + 1, -1);
    queue<int> Q;
    for(auto& i : ZOM){
        Q.push(i);
        dist[i] = 0;
    }
    while(!Q.empty()){
        int v{Q.front()};
        Q.pop();
        for(auto& i : g[v]){
            if(dist[i] == -1){
                dist[i] = dist[v] + 1;
                Q.push(i);
            }
        }
    }
    priority_queue<st> pQ;
    vl dijk(n + 1, LLONG_MAX);
    pQ.push({1, 0});
    dijk[1] = 0;
    while(!pQ.empty()){
        int v{pQ.top().v};
        ll w{pQ.top().w};
        pQ.pop();
        if(dijk[v] < w) continue;
        for(auto& i : g[v]){
            int nv{i};
            ll nw{w};
            if(dist[nv] == 0) continue;
            if(i != n){
                if(dist[nv] <= s) nw += q;
                else nw += p;
            }
            if(dijk[nv] > nw){
                dijk[nv] = nw;
                pQ.push({nv, nw});
            }
        }
    }
    cout << dijk[n];
}
