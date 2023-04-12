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
    int v, t, h;
    bool operator< (const st& x) const{
        return tie(t, h) > tie(x.t, x.h); 
    }
};


int main(){
	fastio;
    int k, n, m;
    cin >> k >> n >> m;
    vector<vector<st>> g(n + 1);
    for(int i{0}; i < m; ++i){
        int a, b, t, h;
        cin >> a >> b >> t >> h;
        g[a].push_back({b, t, h});
        g[b].push_back({a, t, h});
    }
    int a, b;
    cin >> a >> b;
    priority_queue<st> pQ;
    vector<vi> dijk(n + 1, vi(k, MAX));
    pQ.push({a, 0, 0});
    vi ch(n + 1, MAX);
    while(!pQ.empty()){
        int v{pQ.top().v};
        int t{pQ.top().t};
        int h{pQ.top().h};
        pQ.pop();
        if(dijk[v][h] < t) continue;
        if(ch[v] < h) continue;
        ch[v] = h;
        for(auto& i : g[v]){
            int nv{i.v};
            int nt{t + i.t};
            int nh{h + i.h};
            if(nh >= k) continue;
            if(dijk[nv][nh] > nt){
                dijk[nv][nh] = nt;
                pQ.push({nv, nt, nh});
            }
        }
    }
    int ans = *min_element(dijk[b].begin(), dijk[b].end());
    if(ans == MAX) cout << -1;
    else cout << ans;
}
