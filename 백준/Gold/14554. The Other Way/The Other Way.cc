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
#define MOD 1000000009
using namespace std;

struct st{
    int v;
    ll w;
    bool operator< (const st& a) const{
        return w > a.w;
    }
};

int main(){
	fastio;
    int n, m, s, e;
    cin >> n >> m >> s >> e;
    vector<vp> g(n + 1);
    for(int i{0}; i < m; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    priority_queue<st> pQ;
    vl dijk(n + 1, LLONG_MAX);
    vi cnt(n + 1);
    dijk[s] = 0;
    cnt[s] = 1;
    pQ.push({s, 0});
    while(!pQ.empty()){
        int v{pQ.top().v};
        ll w{pQ.top().w};
        pQ.pop();
        if(dijk[v] < w) continue;
        for(auto& i : g[v]){
            int nv{i.first};
            ll nw{w + i.second};
            if(dijk[nv] > nw){
                dijk[nv] = nw;
                cnt[nv] = cnt[v];
                cnt[nv] %= MOD;
                pQ.push({nv, nw});
            }
            else if(dijk[nv] == nw){
                cnt[nv] += cnt[v];
                cnt[nv] %= MOD;
            }
        }
    }
    cout << cnt[e];
}
