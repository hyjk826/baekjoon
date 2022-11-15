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
    bool operator< (const st& a) const{
        return w > a.w;
    }
};

int main() {
	fastio;
    int n, m, k;
    cin >> n >> m >> k;
    vector<vp> g(n + 1);
    for(int i{0}; i < m; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        g[b].push_back({a, c});
    }
    vl dijk(n + 1, LLONG_MAX);
    priority_queue<st> pQ;
    for(int i{0}; i < k; ++i){
        int a;
        cin >> a;
        dijk[a] = 0;
        pQ.push({a, 0});
    }
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
                pQ.push({nv, nw});
            }
        }
    }
    ll mx{0};
    for(int i{1}; i <= n; ++i){
        mx = max(mx, dijk[i]);
    }
    for(int i{1}; i <= n; ++i){
        if(mx == dijk[i]){
            cout << i << "\n";
            cout << mx;
            return 0;
        }
    }
}
	

