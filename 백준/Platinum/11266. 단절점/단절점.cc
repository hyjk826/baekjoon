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
vector<vi> g(10000);
vector<bool> isCurVertex(10000);
vi order(10000, -1);
int cnt{0};

int dfs(int cur, bool isRoot){
    order[cur] = cnt++;
    int child{0};
    int mn = order[cur];
    for(auto& i : g[cur]){
        if(order[i] == -1){
            child++;            
            int k = dfs(i, 0);
            if(!isRoot && k >= order[cur]){
                isCurVertex[cur] = 1;
            }
            mn = min(mn, k);
            
        }
        else mn = min(mn, order[i]);
    }
    if(isRoot && child >= 2) isCurVertex[cur] = 1;
    return mn;
}


int main() {
	fastio;
    cin >> n >> m;
    g.resize(n);
    for(int i{0}; i < m; ++i){
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i{0}; i < n; ++i){
        if(order[i] == -1) dfs(i, 1);
    }
    vi ans;
    for(int i{0}; i < n; ++i){
        if(isCurVertex[i]) ans.push_back(i + 1);
    }
    cout << ans.size() << "\n";
    for(auto& i : ans) cout << i << " ";
}
	
