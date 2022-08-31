// 2022-08-31
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

struct st{
    int v, dis;
    bool operator< (const st& a) const{
        return dis > a.dis;
    }
};

priority_queue<int> ans[1001];
priority_queue<st> pQ;
vector<vector<st>> g(1001);

int main() {
	fastio;
    int n, m, k;
    cin >> n >> m >> k;
    for(int i{0}; i < m; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
    }
    pQ.push({1, 0});
    ans[1].push(0);
    while(!pQ.empty()){
        int v{pQ.top().v};
        int dis{pQ.top().dis};
        pQ.pop();
        for(auto& u : g[v]){
            int nv = u.v;
            int ndis = dis + u.dis;
            if((int)ans[nv].size() < k){
                ans[nv].push(ndis);
                pQ.push({nv, ndis});
            } 
            else if(ans[nv].top() > ndis){
                ans[nv].pop();
                ans[nv].push(ndis);
                pQ.push({nv, ndis});
            }
        }
    }
    for(int i{1}; i <= n; ++i){
        if(ans[i].size() < k) cout << -1 << "\n";
        else cout << ans[i].top() << "\n";
    }
}

