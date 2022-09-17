// 2022-09-18
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
    int v, c, d;
    bool operator< (const st& a) const{
        if(d == a.d) return c > a.c;
        else return d > a.d;
    }
};

int main() {
	fastio;
    int t;
    cin >> t;
    while(t--){
        int n, m, k;
        cin >> n >> k >> m;
        vector<vector<st> > g(n);
        vector<vi> dijk(n, vi(k + 1, MAX));
        for(int i{0}; i < m; ++i){
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            a--;
            b--;
            g[a].push_back({b, c, d});
        }
        dijk[0][0] = 0;
        priority_queue<st> pQ;
        pQ.push({0, 0, 0});
        while(!pQ.empty()){
            int v{pQ.top().v};
            int c{pQ.top().c};
            int d{pQ.top().d};
            pQ.pop();
            if(dijk[v][c] < d) continue;
            for(auto& i : g[v]){
                int nv{i.v};
                int nc{i.c};
                int nd{i.d};
                if(c + nc > k) continue;
                if(dijk[nv][c + nc] > d + nd){
                    dijk[nv][c + nc] = d + nd;
                    pQ.push({nv, c + nc, d + nd});
                }
            }
        }
        int ans{MAX};
        for(int i{0}; i <= k; ++i){
            ans = min(ans, dijk[n - 1][i]);
        }
        if(ans == MAX) cout << "Poor KCM\n";
        else cout << ans << "\n";
    }
}
	

