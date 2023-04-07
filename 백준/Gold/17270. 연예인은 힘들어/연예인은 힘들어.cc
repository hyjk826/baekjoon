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
        g[b].push_back({a, c});
    }
    int a, b;
    cin >> a >> b;
    function<vi(int)> f = [&](int start){
        priority_queue<st> pQ;
        vi dijk(n + 1, MAX);
        dijk[start] = 0;
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
    vi A = f(a);
    vi B = f(b);
    int mn{MAX};
    int idx{-1};
    for(int i{1}; i <= n; ++i){
        if(i == a || i == b) continue;
        if(A[i] == MAX || B[i] == MAX) continue;
        mn = min(mn, A[i] + B[i]);
    }
    vp X;
    for(int i{1}; i <= n; ++i){
        if(i == a || i == b) continue;
        if(A[i] == MAX || B[i] == MAX) continue;
        if(A[i] > B[i]) continue;
        if(mn == A[i] +B[i]){
            X.push_back({A[i], i});
        }
    }
    sort(X.begin(), X.end());
    if(X.empty()) cout << -1;
    else cout << X[0].second;
}
