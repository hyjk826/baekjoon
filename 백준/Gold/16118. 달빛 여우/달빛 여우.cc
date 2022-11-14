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
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

struct st1{
    int v; ll w;
    bool operator< (const st1& a) const{
        return w > a.w;
    }
};

struct st2{
    int v; ll w; int status;
    bool operator< (const st2& a) const{
        return w > a.w;
    }
};


int main() {
	fastio;
    int n, m;
    cin >> n >> m;
    vector<vp> g(n + 1);
    for(int i{0}; i < m; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        c *= 2;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    vl dijk1(n + 1, LLONG_MAX);
    dijk1[1] = 0;
    priority_queue<st1> pQ;
    pQ.push({1, 0});
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
    vector<vl> dijk2(n + 1, vl(2, LLONG_MAX));
    dijk2[1][0] = 0;
    priority_queue<st2> pQ2;
    pQ2.push({1, 0, 0});
    while(!pQ2.empty()){
        int v{pQ2.top().v};
        ll w{pQ2.top().w};
        int status{pQ2.top().status};
        pQ2.pop();
        if(dijk2[v][status] < w) continue;
        for(auto& i : g[v]){
            int nv{i.first};
            ll nw{w};
            if(status == 0) nw += i.second / 2;
            else nw += i.second * 2;
            if(dijk2[nv][status ^ 1] > nw){
                dijk2[nv][status ^ 1] = nw;
                pQ2.push({nv, nw, status ^ 1});
            }
        }
    }
    int ans{0};
    for(int i{2}; i <= n; ++i){
        if(dijk1[i] < min(dijk2[i][0], dijk2[i][1])) ans++;
    }
    cout << ans;
}
	

