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
    int v, k;
    ll w;
    bool operator< (const st& a) const{
        return w > a.w;
    }
};

vector<st> g[501];
ll dijk[501][501];

void solve(){
	int n, m, mk;
    cin >> n >> m >> mk;
    for(int i{0}; i < m; ++i){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        g[a].push_back({b, c, d});
    }
    priority_queue<st> pQ;
    pQ.push({1, 0, 0});
    dijk[1][0] = 0;
    for(int i{1}; i <= n; ++i){
        for(int j{0}; j <= mk; ++j) dijk[i][j] = LLONG_MAX;
    }
    vi ch(n + 1, MAX);
    while(!pQ.empty()){
        int v{pQ.top().v};
        int k{pQ.top().k};
        ll w{pQ.top().w};
        pQ.pop();
        if(dijk[v][k] < w) continue;
        if(ch[v] <= k) continue;
        ch[v] = k;
        for(auto& i : g[v]){
            ll need = i.w - w % i.w;
            if(need == i.w) need = 0;
            if(dijk[i.v][k] > w + need + i.k){
                dijk[i.v][k] = w + need + i.k;
                pQ.push({i.v, k, w + need + i.k});
            }
            if(k < mk && dijk[i.v][k + 1] > w + i.k){
                dijk[i.v][k + 1] = w + i.k;
                pQ.push({i.v, k + 1, w + i.k});
            }
        }
    }    
    ll ans{LLONG_MAX};
    for(int i{0}; i <= mk; ++i){
        ans = min(ans, dijk[n][i]);
    }
    if(ans == LLONG_MAX) ans = -1;
    cout << ans << "\n";
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
