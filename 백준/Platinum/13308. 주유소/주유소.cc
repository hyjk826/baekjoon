// 2022-11-14
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
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

struct st{
    ll v, w, c;
    bool operator< (const st a) const{
        return w > a.w;
    }
};


int main() {
	fastio;
    int n, m;
    cin >> n >> m;
    vl cost(n + 1);
    for(int i{1}; i <= n; ++i){
        cin >> cost[i];
    }
    vector<vector<pl>> g(n + 1);
    for(int i{0}; i < m; ++i){
        ll a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    priority_queue<st> pQ;
    pQ.push({1, 0, cost[1]});
    vector<vl> dijk(n + 1, vl(2501, LLONG_MAX));
    while(!pQ.empty()){
        ll v{pQ.top().v};
        ll w{pQ.top().w};
        ll c{pQ.top().c};
        pQ.pop();
        if(v == n){
            cout << w;
            return 0;
        }
        if(dijk[v][c] < w) continue;
        for(auto& i : g[v]){
            ll nv{i.first};
            ll k = min(cost[v], c);
            ll nw{w + k * i.second};
            if(dijk[nv][k] > nw){
                dijk[nv][k] = nw;
                pQ.push({nv, nw, k});
            }
        }
    }
}
	

