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

int main(){
	fastio;
    int n, m;
    cin >> n >> m;
    priority_queue<st> pQ;
    vl dijk(n + 1, (ll)1e18);
    for(int i{1}; i <= n; ++i){
        int cost;
        cin >> cost;
        dijk[i] = cost;
        pQ.push({i, cost});
    }  
    vector<vp> g(n + 1);
    for(int i{0}; i < m; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        g[b].push_back({c, a});
        g[c].push_back({b, a});
    }
    while(!pQ.empty()){
        int v{pQ.top().v};
        ll w{pQ.top().w};
        if(v == 1){
            cout << w; return 0;
        }
        pQ.pop();
        if(dijk[v] < w) continue;
        for(auto& i : g[v]){
            int nv{i.first};
            if(dijk[i.second] > w + dijk[nv]){
                dijk[i.second] = w + dijk[nv];
                pQ.push({i.second, dijk[i.second]});
            }
        }
    }
}
