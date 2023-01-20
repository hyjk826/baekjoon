// 2023-01-21
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
    ll v, w;
    bool operator< (const st& a) const{
        return w > a.w;
    }
};

int main(){
	fastio;
    int n, m, s, e;
    ll c;
    cin >> n >> m >> s >> e >> c;
    vector<vpl> g(n + 1);
    for(int i{0}; i < m; ++i){
        ll a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    function<ll(int)> f = [&](int k){
        vl dijk(n + 1, LLONG_MAX);
        dijk[s] = 0;
        priority_queue<st> pQ;
        pQ.push({s, 0});
        while(!pQ.empty()){
            ll v{pQ.top().v};
            ll w{pQ.top().w};
            pQ.pop();
            if(v == e) return dijk[e];
            if(dijk[v] < w) continue;            
            for(auto& i : g[v]){
                if(i.second > k) continue;
                ll nv{i.first};
                ll nw{w + i.second};
                if(dijk[nv] > nw){
                    dijk[nv] = nw;
                    pQ.push({nv, nw});
                }
            }
        }
        return dijk[e];
    };
    int l{1}, r{(int)1e9};
    int ans{-1};
    while(l <= r){
        int mid{(l + r) / 2};
        if(f(mid) <= c){
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << ans;
}
