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

struct edge{
    int a, b, w;
};

vi p((int)1e5 + 1);

int find(int a){
    if(a == p[a]) return a;
    return p[a] = find(p[a]);
}

bool merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a != b){
        p[a] = b;
        return true;
    }
    return false;
}

int main(){
	fastio;
    int n, m, k, q;
    cin >> n >> m >> k >> q;
    vector<vp> g(n + 1);
    for(int i{0}; i < m; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    priority_queue<st> pQ;
    vi dijk(n + 1, MAX);
    for(int i{0}; i < k; ++i){
        int a;
        cin >> a;
        dijk[a] = 0;
        pQ.push({a, 0});
    }
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
    vp query(q);
    for(int i{0}; i < q; ++i){
        cin >> query[i].first >> query[i].second;
    }
    vector<edge> A;
    for(int i{1}; i <= n; ++i){
        for(auto& j : g[i]){
            A.push_back({i, j.first, min(dijk[i], dijk[j.first])});
        }   
    }
    sort(A.begin(), A.end(), [&](edge& x, edge& y){
        return x.w > y.w;
    });
    vi l(q), r(q, (int)A.size() - 1);
    vi ans(q);
    while(1){
        bool ok = false;
        vector<vi> mid((int)A.size());
        for(int i{0}; i < q; ++i){
            if(l[i] <= r[i]){
                ok = true;
                mid[(l[i] + r[i]) >> 1].push_back(i);
            }
        }
        if(!ok) break;
        for(int i{1}; i <= n; ++i) p[i] = i;
        for(int i{0}; i < (int)A.size(); ++i){
            merge(A[i].a, A[i].b);
            for(auto& j : mid[i]){
                if(find(query[j].first) == find(query[j].second)){
                    ans[j] = A[i].w;
                    r[j] = i - 1;
                }
                else l[j] = i + 1;
            }
        }
    }
    for(auto& i : ans) cout << i << "\n";
}
