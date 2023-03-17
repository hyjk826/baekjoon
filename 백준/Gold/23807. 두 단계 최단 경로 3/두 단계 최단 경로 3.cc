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
    int v;
    ll w;
    bool operator< (const st &a) const{
        return w > a.w;
    }
};

vector<vp> g((int)1e5 + 1);
int n, m;

vl f(int s){
    vl dijk(n + 1, (ll)1e17);
    priority_queue<st> pQ;
    pQ.push({s, 0});
    dijk[s] = 0;
    while(!pQ.empty()){
        int v{pQ.top().v};
        ll w{pQ.top().w};
        pQ.pop();
        if(dijk[v] < w) continue;
        for(auto& i : g[v]){
            int nv{i.first};
            ll nw{w + i.second};
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
    cin >> n >> m;
    for(int i{0}; i < m; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    int s, e;
    cin >> s >> e;
    int p;
    cin >> p;
    vi P(p);
    vector<vl> dd;
    for(int i{0}; i < p; ++i){
        cin >> P[i];
        dd.push_back(f(P[i]));
    }
    ll ans{LLONG_MAX};
    vi ch(n + 1);
    function<void(int, vi&)> dfs = [&](int L, vi& A){
        if(L == 3){
            ll sum = 0;
            sum += dd[A[0]][s];
            sum += dd[A[0]][P[A[1]]];
            sum += dd[A[1]][P[A[2]]];
            sum += dd[A[2]][e];
            ans = min(ans, sum);
        }
        else{
            for(int i{0}; i < p; ++i){
                if(ch[i]) continue;
                A.push_back(i);
                ch[i] = 1;
                dfs(L + 1, A);
                ch[i] = 0;
                A.pop_back();
            }
        }
    };
    vi A;
    dfs(0, A);
    if(ans >= (ll)1e17) cout << -1;
    else cout << ans;
}
