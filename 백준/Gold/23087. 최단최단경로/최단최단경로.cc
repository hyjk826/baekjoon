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
#define MOD 1000000009
using namespace std;

struct st{
    int v; ll w; int cnt;
    bool operator< (const st& a) const{
        if(w == a.w) return cnt > a.cnt;
        return w > a.w;
    }
};

int main() {
	fastio;
    int n, m, s, d;
    cin >> n >> m >> s >> d;
    vector<vp> g(n + 1);
    for(int i{0}; i < m; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
    }   
    vl dijk(n + 1, LLONG_MAX);
    vl A(n + 1, LLONG_MAX);
    vl B(n + 1);
    B[s] = 1;
    priority_queue<st> pQ;
    pQ.push({s, 0, 0});
    dijk[s] = 0;
    A[s] = 0;
    while(!pQ.empty()){
        int v{pQ.top().v};
        ll w{pQ.top().w};
        int cnt{pQ.top().cnt};
        pQ.pop();
        if(dijk[v] < w || A[v] < cnt) continue;
        for(auto& i : g[v]){
            int nv{i.first};
            ll nw{i.second + w};
            if(dijk[nv] > nw || (dijk[nv] == nw && A[nv] > cnt + 1)){
                dijk[nv] = nw;
                A[nv] = cnt + 1;
                B[nv] = B[v];
                pQ.push({nv, nw, cnt + 1});
            }
            else if(dijk[nv] == nw && A[nv] == cnt + 1){                
                B[nv] += B[v];
                B[nv] %= MOD;
            }
        }
    }
    if(dijk[d] == LLONG_MAX){
        cout << -1;
        return 0;
    }
    cout << dijk[d] << "\n";
    cout << A[d] << "\n";
    cout << B[d] << "\n";
}
	

