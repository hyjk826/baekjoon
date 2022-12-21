// 2022-12-21
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
    int n;
    cin >> n;
    vi vec(n + 1);
    int sum{0};
    for(int i{1}; i <= n; ++i){
        cin >> vec[i];
        sum += vec[i];
    }
    vector<vp> g(sum + 1);
    for(int i{1}; i <= n; ++i){
        for(int j{vec[i - 1] + 1}; j < vec[i - 1] + vec[i]; ++j){
            g[j].push_back({j + 1, 1});
            g[j + 1].push_back({j, 1});
        }
        vec[i] += vec[i - 1];
    }
    int m;
    cin >> m;
    for(int i{0}; i < m; ++i){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int x = vec[a - 1] + b;
        int y = vec[c - 1] + d;
        g[x].push_back({y, 0});
        g[y].push_back({x, 0});
    }
    int q;
    cin >> q;
    while(q--){
        int a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;
        int s = vec[b - 1] + c;
        e += vec[d - 1];
        vi dijk(sum + 1, MAX);
        dijk[s] = 0;
        priority_queue<st> pQ;
        pQ.push({s, 0});
        while(!pQ.empty()){
            int v{pQ.top().v};
            int w{pQ.top().w};
            pQ.pop();
            if(dijk[v] < w) continue;
            for(auto& i : g[v]){
                int nv{i.first};
                int nw{w};
                if(i.second == 0) nw += a;
                else nw++;
                if(dijk[nv] > nw){
                    dijk[nv] = nw;
                    pQ.push({nv, nw});
                }
            }
        }   
        cout << dijk[e] << "\n";
    }

}
	
