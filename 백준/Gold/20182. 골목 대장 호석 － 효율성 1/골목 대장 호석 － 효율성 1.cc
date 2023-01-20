// 2023-01-21
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
    int n, m, c, s, e;
    cin >> n >> m >> s >> e >> c;
    vector<vp> g(n + 1);
    for(int i{0}; i < m; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    function<int(int)> f = [&](int k){
        vi dijk(n + 1, MAX);
        dijk[s] = 0;
        priority_queue<st> pQ;
        pQ.push({s, 0});
        while(!pQ.empty()){
            int v{pQ.top().v};
            int w{pQ.top().w};
            pQ.pop();
            for(auto& i : g[v]){
                if(i.second > k) continue;
                int nv{i.first};
                int nw{w + i.second};
                if(dijk[nv] > nw){
                    dijk[nv] = nw;
                    pQ.push({nv, nw});
                }
            }
        }
        return dijk[e];
    };
    int l{1}, r{20};
    int ans{-1};
    while(l <= r){
        int mid{(l + r) / 2};
        if(f(mid) <= c){
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << ans;
}
