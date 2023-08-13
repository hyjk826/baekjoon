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
    int v, c;
    ll w;
    bool operator< (const st& a) const{
        return w > a.w;
    }
};

void solve(){
	int n, m;
    cin >> n >> m;
    vi cost(n + 1);
    for(int i{1}; i <= n; ++i) cin >> cost[i];
    vector<vp> g(n + 1);
    for(int i{0}; i < m; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    vector<vl> dijk(n + 1, vl(2501, LLONG_MAX));
    priority_queue<st> pQ;
    pQ.push({1, cost[1], 0});
    dijk[1][cost[1]] = 0;
    vi ch(n + 1, -1);
    ch[1] = cost[1];
    while(!pQ.empty()){
        int v{pQ.top().v};
        int c{pQ.top().c};
        ll w{pQ.top().w};
        pQ.pop();
        if(dijk[v][c] < w) continue;
        if(cost[v] < c) continue;
        cost[v] = c;
        for(auto& i : g[v]){
            int nv{i.first};
            ll nw{i.second * c + w};
            int nc = min(c, cost[nv]);
            if(dijk[nv][nc] > nw){
                dijk[nv][nc] = nw;
                pQ.push({nv, nc, nw});
            }
        } 
    }
    ll ans{LLONG_MAX};
    for(int i{1}; i <= 2500; ++i){
        ans = min(ans, dijk[n][i]);
    }
    cout << ans << "\n";
}


int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
