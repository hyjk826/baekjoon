// 2022-11-19
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

int main() {
	fastio;
    int t;
    cin >> t;
    for(int T{1}; T <= t; ++T){
        int n, m;
        cin >> m >> n;
        vector<vp> g(n + 1);
        for(int i{0}; i < m; ++i){
            int a, b, c;
            cin >> a >> b >> c;
            g[a].push_back({b, c});
            g[b].push_back({a, c});
        }
        cout << "Case #" << T << ": ";
        vi dijk(n, MAX);
        vi p(n, -1);
        priority_queue<st> pQ;
        pQ.push({0, 0});
        dijk[0] = 0;
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
                    p[nv] = v;
                    pQ.push({nv, nw});
                }
            }
        }
        if(dijk[n - 1] == MAX) cout << -1 << "\n";
        else{
            vi ans;
            int k{n - 1};
            while(1){
                if(k == -1) break;
                ans.push_back(k);
                k = p[k];
            }
            reverse(ans.begin(), ans.end());
            for(auto& i : ans) cout << i << " ";
            cout << "\n";
        }

    }
}
	

