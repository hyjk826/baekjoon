// 2022-11-26
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

int dist(pi x, pi y){
    int a = x.first - y.first;
    int b = x.second - y.second;
    double d = sqrt(a * a + b * b);
    return (int)d;
}

struct st{
    int v, w;
    bool operator< (const st& a) const{
        return w > a.w;
    }
};

bool checkPrime(int n){
    if(n == 1 || n == 0) return false;
    for(int i{2}; i * i <= n; ++i){
        if(n % i == 0) return false;
    }
    return true;
}


int main() {
	int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    int n;
    cin >> n;
    vp vec(n + 2);
    vec[0] = {sx, sy};
    vec[n + 1] = {tx, ty};
    for(int i{1}; i <= n; ++i){
        cin >> vec[i].first >> vec[i].second;
    }
    vector<vp> g(n + 2);
    for(int i{0}; i <= n + 1; ++i){
        for(int j{i + 1}; j <= n + 1; ++j){
            int a = dist(vec[i], vec[j]);
            if(checkPrime(a)){
                g[i].push_back({j, a});
                g[j].push_back({i, a});   
            }
        }
    }
    priority_queue<st> pQ;
    pQ.push({0, 0});
    vi dijk(n + 2, MAX);
    while(!pQ.empty()){
        int v{pQ.top().v};
        int w{pQ.top().w};
        pQ.pop();
        if(dijk[v] < w) continue;
        for(auto& i : g[v]){
            int nv{i.first};
            int nw{i.second + w};
            if(dijk[nv] > nw){
                dijk[nv] = nw;
                pQ.push({nv, nw});
            }
        }
    }
    if(dijk[n + 1]== MAX) cout << -1;
    else cout << dijk[n + 1];
}
	
