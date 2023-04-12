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


int main(){
	fastio;
    int n, m;
    cin >> n >> m;
    vector<vp> g(n + 1);
    for(int i{0}; i < m; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
    }
    int x, y, z;
    cin >> x >> y >> z;
    function<int(int,int, int)> f = [&](int a, int b, int c){
        vi dijk(n + 1, MAX);
        priority_queue<st> pQ;
        pQ.push({a, 0});
        dijk[a] = 0;
        while(!pQ.empty()){
            int v{pQ.top().v};
            int w{pQ.top().w};
            pQ.pop();
            if(dijk[v] < w) continue;
            for(auto& i : g[v]){
                int nv{i.first};
                int nw{w + i.second};
                if(nv == c) continue;
                if(dijk[nv] > nw){
                    dijk[nv] = nw;
                    pQ.push({nv, nw});
                }
            }
        }
        return dijk[b];
    };
    int a = f(x, y, -1);
    int b = f(y, z, -1);
    if(a == MAX || b == MAX) cout << -1 << " ";
    else cout << a + b << " ";
    a = f(x, z, y);
    if(a == MAX) cout << -1;
    else cout << a;
}
