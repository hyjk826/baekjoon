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
#define vpl vector<pl>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

struct st{
    int v; ll w;
    bool operator< (const st a) const{
        return w > a.w;
    }
};

int main() {
	fastio;
    int n, m, d, e;
    cin >> n >> m >> d >> e;
    vi H(n + 1);
    for(int i{1}; i <= n; ++i){
        cin >> H[i];
    }
    vector<vp> g(n + 1);
    for(int i{0}; i < m; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    priority_queue<st> pQ;
    vl dijk(n + 1, LLONG_MAX);
    dijk[1] = 0;
    pQ.push({1, 0});
    while(!pQ.empty()){
        int v{pQ.top().v};
        ll w{pQ.top().w};
        pQ.pop();
        if(dijk[v] < w) continue;
        for(auto& i : g[v]){
            if(H[v] >= H[i.first]) continue;
            int nv{i.first};
            ll nw{i.second + w};
            if(dijk[nv] > nw){
                dijk[nv] = nw;
                pQ.push({nv, nw});
            }
        }
    }
    vl dijk2(n + 1, LLONG_MAX);
    dijk2[n] = 0;
    pQ.push({n, 0});
    while(!pQ.empty()){
        int v{pQ.top().v};
        ll w{pQ.top().w};
        pQ.pop();
        if(dijk2[v] < w) continue;
        for(auto& i : g[v]){
            if(H[v] >= H[i.first]) continue;
            int nv{i.first};
            ll nw{i.second + w};
            if(dijk2[nv] > nw){
                dijk2[nv] = nw;
                pQ.push({nv, nw});
            }
        }
    }
    ll ans{-LLONG_MAX};
    for(int i{2}; i <= n - 1; ++i){
        if(dijk[i] == LLONG_MAX || dijk2[i] == LLONG_MAX) continue;
        ans = max(ans, 1LL * e * H[i] - (dijk[i] + dijk2[i]) * d);
    }
    if(ans == -LLONG_MAX) cout << "Impossible";
    else cout << ans;
}
	

