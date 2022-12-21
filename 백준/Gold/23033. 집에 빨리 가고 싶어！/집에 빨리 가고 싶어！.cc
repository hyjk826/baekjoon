// 2022-12-21
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

struct st1{
    int v, w, t;
};

struct st{
    int v, w;
    bool operator< (const st& a) const{
        return w > a.w;
    }
};

int main(){
	fastio;
	int n, m;
    cin >> n >> m;
    vector<vector<st1> > g(n + 1);
    for(int i{0}; i < m; ++i){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        g[a].push_back({b, c, d});
    }
    vi dijk(n + 1, MAX);
    dijk[1] = 0;
    priority_queue<st> pQ;
    pQ.push({1, 0});
    while(!pQ.empty()){
        int v{pQ.top().v};
        int w{pQ.top().w};
        pQ.pop();
        if(dijk[v] < w) continue;
        for(auto& i : g[v]){
            int nv{i.v};
            int nw{i.w + w};
            int a = w % i.t;
            if(a != 0){
                nw += i.t - a;
            }
            if(dijk[nv] > nw){
                dijk[nv] = nw;
                pQ.push({nv, nw});
            }
        }
    }
    cout << dijk[n];
}
	
