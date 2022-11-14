// 2022-11-14
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
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int n, m, p;
vector<vp> g(5001);

struct st{
    int v, w;
    bool operator< (const st& a) const{
        return w > a.w;
    }
};

vi f(int root){
    priority_queue<st> pQ;
    vi dijk(n + 1, MAX);
    dijk[root] = 0;
    pQ.push({root, 0});
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
}


int main() {
	fastio;    
    cin >> n >> m >> p;
    for(int i{0}; i < m; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    vi A = f(1);
    vi B = f(p);
    if(A[p] + B[n] == A[n]){
        cout << "SAVE HIM";
    }
    else cout << "GOOD BYE";
}
	

