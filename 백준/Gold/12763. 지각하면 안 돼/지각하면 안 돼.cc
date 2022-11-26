// 2022-11-26
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
    int v, time, w;
    bool operator< (const st& a) const{
        return w > a.w;
    }
};



int main() {
	int n, t, m;
    cin >> n >> t >> m;
    vector<vi> dijk(n + 1, vi(t + 1, MAX));
    int L;
    cin >> L;
    vector<vector<st>> g(n + 1);
    for(int i{0}; i < L; ++i){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        g[a].push_back({b, c, d});
        g[b].push_back({a, c, d});
    }
    priority_queue<st> pQ;
    pQ.push({1, 0, 0});
    while(!pQ.empty()){
        int v{pQ.top().v};
        int time{pQ.top().time};
        int w{pQ.top().w};
        pQ.pop();
        if(dijk[v][time] < w) continue;
        for(auto& i : g[v]){
            int nv{i.v};
            int nw{w + i.w};            
            int ntime{time + i.time};
            if(nw <= m && ntime <= t && dijk[nv][ntime] > nw){
                dijk[nv][ntime] = nw;
                pQ.push({nv, ntime, nw});
            }
        }
    }
    int ans{MAX};
    for(int i{0}; i <= t; ++i){
        ans = min(ans, dijk[n][i]);
    }
    if(ans == MAX) cout << -1;
    else cout << ans;
}
	
