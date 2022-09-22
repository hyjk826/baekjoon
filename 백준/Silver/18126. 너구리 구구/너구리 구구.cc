// 2022-09-21
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

int main() {
	fastio;
    int n;
    cin >> n;
    vector<vp> g(n + 1);
    for(int i{0}; i < n - 1; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    vl dist(n + 1, -1);
    dist[1] = 0;
    queue<int> Q;
    Q.push(1);
    ll ans{0};
    while(!Q.empty()){
        int x{Q.front()};
        Q.pop();
        ans = max(ans, dist[x]);
        for(auto& i : g[x]){
            if(dist[i.first] == -1){
                dist[i.first] = dist[x] + i.second;
                Q.push(i.first);
            }
        }
    }
    cout << ans;
}
	

