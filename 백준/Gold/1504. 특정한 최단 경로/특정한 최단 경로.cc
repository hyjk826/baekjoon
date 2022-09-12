// 2022-09-12
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
    int v, dis;
    bool operator< (const st& a) const{
        return dis > a.dis;
    }
};


vector<vector<st>> g(801);
int n, m;

vi f(int s){
    vi dijk(n + 1, MAX);
    dijk[s] = 0;
    queue<st> Q;
    Q.push({s, 0});
    while(!Q.empty()){
        int v{Q.front().v};
        int dis{Q.front().dis};
        Q.pop();
        if(dis > dijk[v]) continue;
        for(auto& i : g[v]){
            int nv{i.v};
            int ndis{i.dis + dis};
            if(dijk[nv] > ndis){
                dijk[nv] = ndis;
                Q.push({nv, dijk[nv]});
            }
        }
    }
    return dijk;
}


int main() {
	fastio;
    cin >> n >> m;
    for(int i{0}; i < m; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    int a, b;
    cin >> a >> b;
    vi A = f(1);
    vi B = f(a);
    vi C = f(b);
    ll k = LLONG_MAX;
    if(A[a] != MAX && B[b] != MAX && C[n] != MAX){
        k = min(k, 1LL * A[a] + B[b] + C[n]);
    }
    if(!(A[b] == MAX || C[a] == MAX || B[n] == MAX)){
        k = min(k, 1LL * A[b] + C[a] + B[n]);
    }
    if(k == LLONG_MAX) cout << -1;
    else cout << k;
}
	

