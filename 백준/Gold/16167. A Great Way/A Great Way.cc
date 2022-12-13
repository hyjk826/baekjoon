// 2022-12-12
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
    int v, w, cnt;
    bool operator< (const st& a) const{
        if(w == a.w) return cnt > a.cnt;
        return w > a.w;
    }
};


int main() {
	fastio;
    int n, m;
    cin >> n >> m;
    vector<vp> g(n + 1);
    for(int i{0}; i < m; ++i){
        int a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;
        int w = c;
        if(e >= 10) w += (e - 10) * d;
        g[a].push_back({b, w});
    }
    vi dijk(n + 1, MAX);
    vi A(n + 1);
    dijk[1] = 0;
    A[1] = 1;
    priority_queue<st> pQ;
    pQ.push({1, 0, 1});
    while(!pQ.empty()){
        int v{pQ.top().v};
        int w{pQ.top().w};
        int cnt{pQ.top().cnt};
        pQ.pop();        
        if(dijk[v] < w) continue;
        if(dijk[v] == w && A[v] < cnt) continue;
        for(auto& i : g[v]){
            int nv{i.first};
            int nw{i.second + w};
            if(dijk[nv] > nw){
                dijk[nv] = nw;
                A[nv] = cnt + 1;
                pQ.push({nv, nw, cnt + 1});
            }
            else if(dijk[nv] == nw && A[nv] > cnt + 1){
                A[nv] = cnt + 1;
                pQ.push({nv, nw, cnt + 1});
            }
        }
    }
    if(dijk[n] == MAX) cout << "It is not a great way.";
    else cout << dijk[n] << " " << A[n];
}
	
