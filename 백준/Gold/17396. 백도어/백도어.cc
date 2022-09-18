// 2022-09-18
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
    ll v, dis;
    bool operator< (const st& a) const{
        return dis > a.dis;
    }
};

int main() {
	fastio;
	int n, m;
    cin >> n >> m;
    vi ch(n);
    for(int i{0}; i < n; ++i){
        cin >> ch[i];
    }
    ch[n - 1] = 0;
    vector<vector<st>> g(n);
    for(int i{0}; i < m; ++i){
        ll a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    vl dijk(n, (ll)1e18);
    dijk[0] = 0;
    priority_queue<st> pQ;
    pQ.push({0, 0});
    while(!pQ.empty()){
        ll v{pQ.top().v};
        ll dis{pQ.top().dis};
        pQ.pop();
        if(dijk[v] < dis) continue;
        for(auto& i : g[v]){
            if(ch[i.v]) continue;
            ll nv{i.v};
            ll ndis{i.dis + dis};
            if(dijk[nv] > ndis){
                dijk[nv] = ndis;
                pQ.push({nv, dijk[nv]});
            }
        }        
    }
    if(dijk.back() == (ll)1e18) cout << -1;
    else cout << dijk.back();
}
	

