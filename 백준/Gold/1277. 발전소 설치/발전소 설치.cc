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
    int v;
    double w;
    bool operator< (const st& a) const{
        return w > a.w;
    }
};

double f(pi a, pi b){
    double x = a.first - b.first;
    double y = a.second - b.second;
    return sqrt(1LL * x * x + 1LL * y * y);
}


int main(){
	fastio;
    int n, k;
    cin >> n >> k;
    double m;
    cin >> m;
    vector<pi> point(n);
    for(int i{0}; i < n; ++i){
        cin >> point[i].first >> point[i].second;
    }
    vector<vi> g(n);
    for(int i{0}; i < k; ++i){
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    priority_queue<st> pQ;
    pQ.push({0, 0});
    vector<double> dijk(n, 1e14);
    dijk[0] = 0;
    while(!pQ.empty()){
        int v{pQ.top().v};
        double w{pQ.top().w};
        pQ.pop();
        if(dijk[v] < w) continue;
        for(auto& i : g[v]){
            if(dijk[i] > w){
                dijk[i] = w;
                pQ.push({i, w});
            }
        }
        for(int i{0}; i < n; ++i){
            if(i == v) continue;
            double d = f(point[v], point[i]);
            if(d > m) continue;
            if(dijk[i] > w + d){
                dijk[i] = w + d;
                pQ.push({i, w + d});
            }
        }
    }
    cout << (ll)(dijk[n - 1] * 1000);
}
