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

vector<vp> g(50001);
vector<vi> dist(50001);


int main(){
	fastio;
    int n, m, q;
    cin >> n >> m >> q;
    vi degree(n + 1);
    for(int i{0}; i < m; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    for(int i{1}; i <= n; ++i){
        sort(g[i].begin(), g[i].end());
    }
    for(int i{1}; i <= n; ++i){
        if(g[i].size() >= 70){
            dist[i].resize(n + 1, MAX);
            dist[i][i] = 0;
            for(auto& j : g[i]){
                dist[i][j.first] = min(dist[i][j.first], j.second);
                for(auto& k : g[j.first]){
                    dist[i][k.first] = min(dist[i][k.first], j.second + k.second);
                }
            }
        }
    }
    unordered_map<int, unordered_map<int, int> > mp;
    while(q--){
        int a, b;
        cin >> a >> b;
        if(g[a].size() < g[b].size()) swap(a, b);
        if(mp.count(a) && mp[a].count(b)){
            cout << mp[a][b] << "\n"; continue;
        }
        int ans{MAX};
        if(g[a].size() >= 70){            
            for(auto& i : g[b]){
                ans = min(ans, dist[a][i.first] + i.second);
            }
        }
        else{
            for(auto& i : g[a]){
                if(i.first == b) ans = min(ans, i.second);
                for(auto& j : g[b]){
                    if(i.first == j.first) ans = min(ans, i.second + j.second);
                    auto it = lower_bound(g[i.first].begin(), g[i.first].end(), make_pair(j.first, 0));
                    if(it != g[i.first].end() && it->first == j.first){
                        ans = min(ans, i.second + j.second + it->second);
                    }
                }
            }
        }
        if(ans == MAX) ans = -1;
        cout << ans << "\n";
        mp[a][b] = ans;
    }
}
