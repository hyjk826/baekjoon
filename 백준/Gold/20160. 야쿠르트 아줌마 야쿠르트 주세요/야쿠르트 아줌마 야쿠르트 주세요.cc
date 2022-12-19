// 2022-12-20
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

int main(){
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
    auto f = [&](int s){
        vi dijk(n + 1, MAX);
        dijk[s] = 0;
        priority_queue<st> pQ;
        pQ.push({s, 0});
        while(!pQ.empty()){
            int v{pQ.top().v};
            int w{pQ.top().w};
            pQ.pop();
            for(auto& i : g[v]){
                int nv{i.first};
                int nw{i.second + w};
                if(dijk[nv] > nw){
                    dijk[nv] = nw;
                    pQ.push({nv, nw});
                }
            }
        }
        return dijk;
    };
    map<int, vi> mp;
    vi A(10);
    for(int i{0}; i < 10; ++i){
        cin >> A[i];
    }
    int k;
    cin >> k;
    vi B = f(k);
    ll sum{0};
    int cur = A[0];
    int ans{MAX};
    if(k == A[0]) ans = k;
    for(int i{1}; i < 10; ++i){
        int dist;
        if(mp.count(cur)){
            dist = mp[cur][A[i]];
        }
        else if(mp.count(A[i])){
            dist = mp[A[i]][cur];
        }
        else{
            vi ret = f(cur);
            mp[cur] = ret;
            dist = ret[A[i]];
        }
        if(dist == MAX) continue;
        sum += dist;
        if(sum >= B[A[i]]) ans = min(ans, A[i]);
        cur = A[i];
    }
    if(ans == MAX) cout << -1;
    else cout << ans;
}
	
