// 2022-11-20
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
    int v, flag;
    ll w;
    bool operator< (const st& a) const{
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
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    int x, z; 
    cin >> x >> z;
    int p;
    cin >> p;
    set<int> s;
    for(int i{0}; i < p; ++i){
        int a;
        cin >> a;
        s.insert(a);
    }
    priority_queue<st> pQ;
    vector<vl> dijk(n + 1, vl(2, LLONG_MAX));
    dijk[x][0] = 0;
    pQ.push({x, 0, 0});
    while(!pQ.empty()){
        int v{pQ.top().v};
        int flag{pQ.top().flag};
        ll w{pQ.top().w};
        pQ.pop();
        if(dijk[v][flag] < w) continue;
        for(auto& i : g[v]){
            int nv{i.first};
            ll nw{w + i.second};
            int nflag = (flag | (s.count(nv)));
            if(dijk[nv][nflag] > nw){
                dijk[nv][nflag] = nw;
                pQ.push({nv, nflag, nw});
            }
        }
    }
    if(dijk[z][1] == LLONG_MAX) cout << -1;
    else cout << dijk[z][1];
}
	

