// 2022-09-17
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

int n, m;
vector<vp> g(10);
vi ch(10);
int ans{MAX};
vi r;

void dfs(int L, int v, int mx, vi& route){
    if(L == n){
        if(ans > mx){
            r = route;
            ans = mx;
        }
    }
    else{
        for(auto& i : g[v]){
            if(L == n - 1 && i.first == 1){
                dfs(L + 1, i.first, max(mx, i.second), route);
            }
            if(ch[i.first] == 0){
                ch[i.first] = 1;
                route.push_back(i.first);
                dfs(L + 1, i.first, max(mx, i.second), route);
                route.pop_back();
                ch[i.first] = 0;
            }
        }
    }
}

int main() {
	fastio;
    cin >> n >> m;
    for(int i{0}; i < m; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
    }
    vi route;
    ch[1] = 1;
    route.push_back(1);
    dfs(0, 1, 0, route);
    if(ans == MAX) cout << -1;
    else{
        cout << ans << "\n";
        for(auto& i : r){
            cout << i << " ";
        }
    }
}
	

