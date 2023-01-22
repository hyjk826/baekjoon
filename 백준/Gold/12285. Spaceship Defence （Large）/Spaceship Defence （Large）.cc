// 2023-01-23
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

void solve(){
    int n;
    cin >> n;
    map<string, vi> mp;
    vector<vp> g(n);
    for(int i{0}; i < n; ++i){
        string str;
        cin >> str;
        mp[str].push_back(i);
    }
    int m;
    cin >> m;
    for(int i{0}; i < m; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        g[a].push_back({b, c});
    }
    for(auto& i : mp){
        for(int j{0}; j < (int)i.second.size() - 1; ++j){
            g[i.second[j]].push_back({i.second[j + 1], 0});
            g[i.second[j + 1]].push_back({i.second[j], 0});
        }
    }
    function<int(int,int)> f = [&](int s, int e){
        vi dijk(n, MAX);
        dijk[s] = 0;
        priority_queue<st> pQ;
        pQ.push({s, 0});
        while(!pQ.empty()){
            int v{pQ.top().v};
            int w{pQ.top().w};
            pQ.pop();
            if(dijk[v] < w) continue;
            if(v == e) return dijk[e];
            for(auto& i : g[v]){
                int nv{i.first};
                int nw{i.second + w};
                if(dijk[nv] > nw){
                    dijk[nv] = nw;
                    pQ.push({nv, nw});
                }
            }
        }
        return dijk[e];
    };
    int q;
    cin >> q;
    while(q--){
        int s, e;
        cin >> s >> e;
        s--; e--;
        int ans = f(s, e);
        if(ans == MAX) cout << -1 << "\n";
        else cout << ans << "\n";
    }
}

int main() {
	fastio;	
	int t;
    cin >> t;
    for(int T{1}; T <= t; ++T){
        cout << "Case #" << T << ": \n";
        solve();
    }
}
	
