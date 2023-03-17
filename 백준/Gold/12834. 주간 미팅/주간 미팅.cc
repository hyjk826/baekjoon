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

vi dijkstra(int n, vector<vp>& g, int s){
    priority_queue<st> pQ;
    vi dijk(n + 1, MAX);
    dijk[s] = 0;
    pQ.push({s, 0});    
    while(!pQ.empty()){
        int v{pQ.top().v};
        int w{pQ.top().w};
        pQ.pop();
        if(dijk[v] < w) continue;
        for(auto& i : g[v]){
            int nv{i.first};
            int nw{w + i.second};
            if(dijk[nv] > nw){
                dijk[nv] = nw;
                pQ.push({nv, nw});
            }
        }
    }
    return dijk;
}

int main(){
	fastio;
    int k, n, m;
    cin >> k >> n >> m;
    int a, b;
    cin >> a >> b;
    vi H(k);
    for(int i{0}; i < k; ++i){
        cin >> H[i];
    }
    vector<vp> g(n + 1);
    for(int i{0}; i < m; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    vi A = dijkstra(n, g, a);
    vi B = dijkstra(n, g, b);
    int ans{0};
    for(int i{0}; i < k; ++i){
        if(A[H[i]] == MAX) ans += -1;
        else ans += A[H[i]];
        if(B[H[i]] == MAX) ans += -1;
        else ans += B[H[i]];
    }
    cout << ans;
}
