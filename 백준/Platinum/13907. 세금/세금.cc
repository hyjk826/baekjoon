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
    int v, w, cnt;
    bool operator< (const st& a) const{
        return w > a.w;
    }
};


int main() {
	fastio;
    int n, m, k;
    cin >> n >> m >> k;
    int s, d; 
    cin >> s >> d;
    vector<vp> g(n + 1);
    for(int i{0}; i < m; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    vi A(k + 1);
    for(int i{1}; i <= k; ++i){
        cin >> A[i];
        A[i] += A[i - 1];
    }
    vector<vi> dijk(n + 1, vi(n + 1, MAX));
    dijk[s][0] = 0;
    priority_queue<st> pQ;
    pQ.push({s, 0, 0});
    while(!pQ.empty()){
        int v{pQ.top().v};
        int w{pQ.top().w};
        int cnt{pQ.top().cnt};
        pQ.pop();
        if(dijk[v][cnt] < w) continue;
        if(cnt == n) continue;
        for(auto& i : g[v]){
            int nv{i.first};
            int nw{i.second + w};
            if(dijk[nv][cnt + 1] > nw){
                dijk[nv][cnt + 1] = nw;
                pQ.push({nv, nw, cnt + 1});
            }
        }
    }
    for(int i{0}; i <= k; ++i){        
        ll ans{LLONG_MAX};
        for(int j{0}; j <= n; ++j){
            ans = min(ans, 1LL * dijk[d][j] + A[i] * j);
        }
        cout << ans << "\n"; 
    }
}
	

