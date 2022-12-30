// 2022-12-30
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
    vector<vp> g(n + 1);
    for(int i{0}; i < m; ++i){
        int a, b;
        cin >> a >> b;
        g[a].push_back({b, i});
        g[b].push_back({a, i});
    }
    priority_queue<st> pQ;
    pQ.push({1, 0});
    vl dijk(n + 1, (ll)1e18);
    dijk[1] = 0;
    while(!pQ.empty()){
        int v{pQ.top().v};
        ll w{pQ.top().w};
        pQ.pop();
        if(dijk[v] < w) continue;
        for(auto& i : g[v]){
            int nv{i.first};
            ll b = w % m;
            ll nw{w + 1};
            if(b > i.second) nw += m - (b - i.second);
            else nw += i.second - b;
            if(dijk[nv] > nw){
                dijk[nv] = nw;
                pQ.push({nv, nw});
            } 
        }
    }
    cout << dijk[n]; 
}
