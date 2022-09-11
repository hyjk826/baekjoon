// 2022-09-11
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define vs vector<string>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

struct st{
    int v, dis;
    bool operator< (const st a) const{
        return dis > a.dis;
    }
};

int main(){
    fastio;
    int n, m;
    cin >> n >> m;
    vector<vector<st>> g(n + 1);
    for(int i{0}; i < m; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
    }
    int a, b;
    cin >> a >> b;
    vi dijk(n + 1, (int)1e9);
    dijk[a] = 0;
    priority_queue<st> pQ;
    pQ.push({a, 0});
    while(!pQ.empty()){
        int v{pQ.top().v};
        int dis{pQ.top().dis};
        pQ.pop();
        if(dis > dijk[v]) continue;
        for(auto& i : g[v]){
            int nv{i.v};
            int ndis{dis + i.dis};
            if(dijk[nv] > ndis){
                dijk[nv] = ndis;
                pQ.push({nv, dijk[nv]});
            }
        }
    }
    cout << dijk[b];
}