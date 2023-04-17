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
    int v; double w;
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
    vector<pi> point(n + 1);
    map<pi, int> mp;
    mp[{0, 0}] = 0;
    for(int i{1}; i <= n; ++i){
        cin >> point[i].first >> point[i].second;
        mp[{point[i].first, point[i].second}] = i;
    }
    vector<vi> g(n + 1);
    for(int i{0}; i <= n; ++i){
        for(int x{-2}; x <= 2; ++x){
            for(int y{-2}; y <= 2; ++y){
                if(x == 0 && y == 0) continue;
                int nx{point[i].first + x};
                int ny{point[i].second + y};
                if(mp.count({nx, ny})){
                    g[i].push_back(mp[{nx, ny}]);
                }
            }
        }
    }
    priority_queue<st> pQ;
    vector<double> dijk(n + 1, 1e14);
    dijk[0] = 0;
    pQ.push({0, 0});
    cout << fixed << setprecision(0);
    while(!pQ.empty()){
        int v{pQ.top().v};
        double w{pQ.top().w};
        pQ.pop();
        if(point[v].second == k){
            cout << w; return 0;
        }
        if(dijk[v] < w) continue;
        for(auto& i : g[v]){
            double d = f(point[v], point[i]);
            if(dijk[i] > w + d){
                dijk[i] = w + d;
                pQ.push({i, w + d});
            }
        }
    }
    cout << -1;
}
