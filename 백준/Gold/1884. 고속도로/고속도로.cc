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
    int v, d, t;
    bool operator< (const st& a) const{
        return d > a.d;
    }
};

int dijk[101][10001];

int main(){
	fastio;
    int k, n, m;
    cin >> k >> n >> m;
    vector<vector<st> > g(n + 1);
    for(int i{0}; i < m; ++i){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        g[a].push_back({b, c, d});
    }
    priority_queue<st> pQ;
    for(int i{1}; i <= n; ++i){
        for(int j{0}; j <= k; ++j){
            dijk[i][j] = MAX;
        }
    }
    pQ.push({1, 0, 0});
    dijk[1][0] = 0;
    vi ch(n + 1, MAX);
    while(!pQ.empty()){
        int v{pQ.top().v};
        int d{pQ.top().d};
        int t{pQ.top().t};
        pQ.pop();
        if(ch[v] <= t) continue;
        ch[v] = t;
        for(auto& i : g[v]){
            int nv{i.v};
            int nd{d + i.d};
            int nt{t + i.t};
            if(dijk[nv][nt] > nd){
                dijk[nv][nt] = nd;
                pQ.push({nv, nd, nt});
            }
        }
    }
    int ans{MAX};
    for(int i{0}; i <= k; ++i){
        ans = min(ans, dijk[n][i]);
    }
    if(ans == MAX) cout << -1;
    else cout << ans;
}
