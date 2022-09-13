// 2022-09-13
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
#define MAX 1000000000
#define MOD 1000000007
using namespace std;

struct st{
    int v, dis;
    bool operator< (const st& a) const{
        return dis > a.dis;
    }
};

int main() {
	fastio;
    int n, m;
    cin >> n >> m;
    vector<vector<st>> g(n + 1);
    for(int i{0}; i < m; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
    }
    int s, e;
    cin >> s >> e;
    vi p(n + 1);
    vi dijk(n + 1, MAX);
    dijk[s] = 0;
    priority_queue<st> Q;
    Q.push({s, 0});
    while(!Q.empty()){
        int v{Q.top().v};
        int dis{Q.top().dis};
        Q.pop();
        if(e == v) break;
        if(dijk[v] < dis) continue;
        for(auto& i : g[v]){
            int nv{i.v};
            int ndis{i.dis + dis};
            if(dijk[nv] > ndis){
                p[nv] = v;
                dijk[nv] = ndis;
                Q.push({nv, dijk[nv]});
            }
        }
    }
    int k = e;
    vi ans;
    for(int i{e}; i != s; i = p[i]){
        ans.push_back(i);
    }
    ans.push_back(s);
    reverse(ans.begin(), ans.end());
    cout << dijk[e] << "\n" << ans.size() << "\n";
    for(auto& i : ans){
        cout << i << " ";
    }
}
	

