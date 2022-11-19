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

int n, m, k;
vector<vp> g;

struct st{
    int v, w;
    bool operator< (const st& a) const{
        return w > a.w;
    }
};

bool ch(int mid){
    vi dijk(n + 1, MAX);
    dijk[1] = 0;
    priority_queue<st> pQ;
    pQ.push({1, 0});
    while(!pQ.empty()){
        int v{pQ.top().v};
        int w{pQ.top().w};
        pQ.pop();
        if(dijk[v] < w) continue;
        for(auto& i : g[v]){
            int nv{i.first};
            int nw{w};
            if(i.second > mid) nw++;
            if(dijk[nv] > nw){
                dijk[nv] = nw;
                pQ.push({nv, nw});
            }
        }
    }
    if(dijk[n] == MAX) return false;
    return dijk[n] <= k;
}


int main() {
	fastio;
    cin >> n >> m >> k;
    g.resize(n + 1);
    for(int i{0}; i < m; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    int l{0}, r{(int)1e7};
    int ans{MAX};
    while(l <= r){
        int mid{(l + r) / 2};
        if(ch(mid)){
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    if(ans == MAX) cout << -1;
    else cout << ans;
}
	

