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
#define MAX 2147000000
#define MOD 1000000007
typedef long long ll;
using namespace std;

struct st{
    int v;
    ll w;
    bool operator< (const st& a) const{
        return w > a.w;
    }
};

void solve(){
	int n, m, k;
    cin >> n >> m >> k;
    vector<vp> g(n + 1);
    for(int i{0}; i < m; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    vi elevator(n + 1);
    for(int i{1}; i <= n; ++i){
        cin >> elevator[i];
    }
    vl dijk1(n + 1, LLONG_MAX);
    vl dijk2(n + 1, LLONG_MAX);
    priority_queue<st> pQ;
    pQ.push({1, 0});
    dijk1[1] = 0;
    while(!pQ.empty()){
        int v{pQ.top().v};
        ll w{pQ.top().w};
        pQ.pop();
        if(dijk1[v] < w) continue;
        for(auto& i : g[v]){
            int nv{i.first};
            ll nw{i.second + w};
            if(dijk1[nv] > nw){
                dijk1[nv] = nw;
                pQ.push({nv, dijk1[nv]});
            }
        }
    }
    pQ.push({n, 0});
    dijk2[n] = 0;
    while(!pQ.empty()){
        int v{pQ.top().v};
        ll w{pQ.top().w};
        pQ.pop();
        if(dijk2[v] < w) continue;
        for(auto& i : g[v]){
            int nv{i.first};
            ll nw{i.second + w};
            if(dijk2[nv] > nw){
                dijk2[nv] = nw;
                pQ.push({nv, dijk2[nv]});
            }
        }
    }
    ll ans{LLONG_MAX};
    for(int i{1}; i <= n; ++i){
        if(elevator[i] == -1) continue;
        if(dijk1[i] == LLONG_MAX || dijk2[i] == LLONG_MAX) continue;
        ans = min(ans, dijk1[i] + dijk2[i] + 1LL * (k - 1) * elevator[i]);
    }
    if(ans == LLONG_MAX) ans = -1;
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
