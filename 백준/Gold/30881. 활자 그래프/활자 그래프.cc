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
    bool operator< (const st& a) const{
        return w > a.w;
    }
};

void solve(){
	int a;
    cin >> a;
    vl ch1(a + 1, LLONG_MAX);
    vl ch2(a + 1, LLONG_MAX);
    for(int g{1}; g <= a; ++g){
        int n, m;
        cin >> n >> m;
        vector<vector<st>> G(n + 1);        
        for(int i{0}; i < m; ++i){
            int a, b, c;
            cin >> a >> b >> c;
            if(c < 0) {
                if(ch2[abs(c)] != LLONG_MAX){
                    G[a].push_back({b, ch2[abs(c)]});
                }
                if(ch1[abs(c)] != LLONG_MAX){
                    G[b].push_back({a, ch1[abs(c)]});
                }
            }
            else{
                G[a].push_back({b, c});
            }                        
        }
        function<ll(int,int)> f = [&](int s, int e){
            priority_queue<st> pQ;
            vl dijk(n + 1, LLONG_MAX);
            pQ.push({s, 0LL});
            while(!pQ.empty()){
                int v{pQ.top().v};
                ll w{pQ.top().w};
                pQ.pop();
                if(dijk[v] < w) continue;
                for(auto& i : G[v]){
                    if(w + i.w > (ll)1e18) continue;
                    if(dijk[i.v] > w + i.w){
                        dijk[i.v] = w + i.w;
                        pQ.push({i.v, dijk[i.v]});
                    }
                }
            }
            return dijk[e];
        };
        ch2[g] = f(1, 2);
        ch1[g] = f(2, 1);
    }
    if(ch2[a] == LLONG_MAX) cout << -1;
    else cout << ch2[a];
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
