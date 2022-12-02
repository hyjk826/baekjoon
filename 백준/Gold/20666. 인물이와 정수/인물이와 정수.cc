// 2022-12-02
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


int main() {
	fastio;
	int n, m;
    cin >> n >> m;
    priority_queue<pl, vpl, greater<pl> > pQ;
    vl cost(n + 1);
    for(int i{0}; i < n; ++i){
        ll a;
        cin >> a;
        cost[i + 1] = a;
    }
    vector<vpl> g(n + 1);
    int p;
    cin >> p;
    for(int i{0}; i < p; ++i){
        ll a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        cost[b] += c;
    }
    for(int i{1}; i <= n; ++i){
        pQ.push({cost[i], i});
    }
    vi ch(n + 1);
    ll ans{0};
    int cnt{0};
    while(cnt < m){
        ll b = pQ.top().first;
        ll a = pQ.top().second;
        pQ.pop();
        if(ch[a] == 0){
            ans = max(ans, b);
            ch[a] = 1;
            cnt++;
        }
        else continue;
        for(auto& j : g[a]){
            if(ch[j.first]) continue;
            cost[j.first] -= j.second;
            pQ.push({cost[j.first], j.first});
        }
    }
    cout << ans;
}
	
