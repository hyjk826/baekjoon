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
    int v, w;
    bool operator< (const st& a) const{
        return w > a.w;
    }
};

int main() {
	int n, m;
    cin >> n >> m;
    vector<vp> g(n + 1);
    for(int i{0}; i < m; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    vi dijk(n + 1, MAX);
    dijk[1] = 0;
    vi p(n + 1);
    priority_queue<st> pQ;
    pQ.push({1, 0});
    while(!pQ.empty()){
        int v{pQ.top().v};
        int w{pQ.top().w};
        pQ.pop();
        if(dijk[v] < w) continue;
        for(auto& i : g[v]){
            int nv{i.first};
            int nw{w + i.second};
            if(dijk[nv] > nw){
                p[nv] = v;
                dijk[nv] = nw;
                pQ.push({nv, nw});
            }
        }
    }
    int a = n;
    vp e;
    while(1){
        if(p[a] == 0) break;
        e.push_back({a, p[a]});
        a = p[a];
    }
    int ans{0};
    for(auto& i : e){
        int qq = i.first;
        int ww = i.second;
        pQ.push({1, 0});
        vi dijk2(n + 1, MAX);
        dijk2[1] = 0;
        while(!pQ.empty()){
            int v{pQ.top().v};
            int w{pQ.top().w};
            pQ.pop();
            if(dijk2[v] < w) continue;
            for(auto& i : g[v]){                
                int nv{i.first};
                if(v == qq && nv == ww) continue;
                if(v == ww && nv == qq) continue;
                int nw{w + i.second};
                if(dijk2[nv] > nw){
                    dijk2[nv] = nw;
                    pQ.push({nv, nw});
                }
            }
        }  
        ans = max(ans, dijk2[n]); 
    }
    cout << ans;
}
	
