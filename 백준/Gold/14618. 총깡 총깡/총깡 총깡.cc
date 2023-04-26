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
    int start, k;
    cin >> start >> k;
    vi ch(n + 1);
    for(int i{0}; i < k; ++i){
        int a;
        cin >> a;
        ch[a] = 1;
    }
    for(int i{0}; i < k; ++i){
        int a;
        cin >> a;
        ch[a] = 2;
    }
    vector<vp> g(n + 1);
    for(int i{0}; i < m; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
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
    int a{MAX}, b{MAX};
    for(int i{1}; i <= n; ++i){
        if(ch[i] == 1) a = min(a, dijk[i]);
        else if(ch[i] == 2) b = min(b, dijk[i]);
    }
    if(a == MAX && b == MAX) cout << -1;
    else if(a <= b){
        cout << "A\n" << a;
    }
    else{
        cout << "B\n" << b;
    }
}
