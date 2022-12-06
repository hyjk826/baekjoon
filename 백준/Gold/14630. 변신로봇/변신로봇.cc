// 2022-12-04
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

int n;
vector<vp> g(1001);

struct st{
    int v, w;
    bool operator< (const st& a) const{
        return w > a.w;
    }
};

int main() {
	fastio;
	cin >> n;
    vs vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    for(int i{0}; i < n; ++i){
        for(int j{i + 1}; j < n; ++j){
            int sum{0};
            for(int k{0}; k < (int)vec[i].size(); ++k){
                sum += (vec[i][k] - vec[j][k]) * (vec[i][k] - vec[j][k]);
            }
            g[i].push_back({j, sum});
            g[j].push_back({i, sum});
        }
    }
    int s, t;
    cin >> s >> t;
    s--;
    t--;
    priority_queue<st> pQ;
    vi dijk(n, MAX);
    dijk[s] = 0;
    pQ.push({s, 0});
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
    cout << dijk[t];
}
	
