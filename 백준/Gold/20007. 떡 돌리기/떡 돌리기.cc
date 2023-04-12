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
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<vp> g(n + 1);
    for(int i{0}; i < m; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    function<vi(int)> f = [&](int a){
        vi dijk(n, MAX);
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
                if(dijk[nv] > nw){
                    dijk[nv] = nw;
                    pQ.push({nv, nw});
                }
            }
        }
        return dijk;
    };
    vi dijk = f(y);
    sort(dijk.begin(), dijk.end());
    for(auto& i : dijk){
        i *= 2;
    }
    if(dijk.back() > x){
        cout << -1; return 0;
    }
    int ans{1};
    int sum = dijk[1];
    for(int i{2}; i < n; ++i){
        if(sum + dijk[i] > x){
            sum = dijk[i];
            ans++;
        }
        else sum += dijk[i];
    }
    cout << ans;
}
