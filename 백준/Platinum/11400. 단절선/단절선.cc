// 2022-12-09
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

int n, m;
vector<vi> g(100000);
vi order(100000, -1);
vp ans;
int cnt{0};

int dfs(int cur, int par){
    order[cur] = cnt++;
    int mn = order[cur];
    for(auto& i : g[cur]){
        if(par == i) continue;
        if(order[i] == -1){         
            int k = dfs(i, cur);
            if(k > order[cur]){
                ans.push_back({min(cur, i), max(cur, i)});
            }
            mn = min(mn, k);           
        }
        else mn = min(mn, order[i]);
    }
    return mn;
}

int main() {
	fastio;
    cin >> n >> m;
    for(int i{0}; i < m; ++i){
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i{0}; i < n; ++i){
        if(order[i] == -1) dfs(i, -1);
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for(auto& i : ans) cout << i.first + 1 << " " << i.second + 1 << "\n";
}
	
