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

struct E{
    int u, v, w;
};

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vp> g(n);
    vector<E> edge(m);
    int sum{0};
    for(int i{0}; i < m; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        edge[i] = {a, b, c};
        g[a].push_back({b, c});
        g[b].push_back({a, c});
        sum += c;
    }
    function<vi(int)> f = [&](int start){
        vi dijk(n, MAX);
        dijk[start] = 0;
        priority_queue<st> pQ;
        pQ.push({start, 0});
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
                    pQ.push({nv, nw});
                }
            }
        }
        return dijk;
    };
    int a, b;
    cin >> a >> b;
    a--; b--;
    vi A = f(a);
    vi B = f(b);
    int mn{MAX};
    for(auto& i : edge){
        mn = min(mn, A[i.u] + B[i.v]);
        mn = min(mn, A[i.v] + B[i.u]);
    }
    cout << sum - mn;
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
