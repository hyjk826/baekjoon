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

unordered_map<int, int> mp[1000001];

void solve(){
    int n, q;
    cin >> n >> q;
    vector<vi> g(n + 1);
    for(int i{2}; i <= n; ++i){
        int a;
        cin >> a;
        g[a].push_back(i);
    }
    vl ans(q);
    for(int i{0}; i < q; ++i){
        int k;
        cin >> k;
        for(int j{0}; j < k; ++j){
            int a;
            cin >> a;
            mp[a][i]++;
        }
    }
    vi depth(n + 1);
    vi path;
    queue<int> Q;
    Q.push(1);
    depth[1] = 0;
    while(!Q.empty()){
        int x{Q.front()};
        Q.pop();
        path.push_back(x);
        for(auto& i : g[x]){
            depth[i] = depth[x] + 1;
            Q.push(i);
        }
    }
    reverse(path.begin(), path.end());
    for(auto& i : path){
        if(g[i].size() == 0) continue;
        for(int j{0}; j < (int)g[i].size(); ++j){
            if(mp[i].size() > mp[g[i][j]].size()){
                swap(mp[i], mp[g[i][j]]);
            }
            for(auto& k : mp[i]){
                if(mp[g[i][j]].count(k.first)){
                    ans[k.first] += 1LL * k.second * mp[g[i][j]][k.first] * depth[i];                        
                }
                mp[g[i][j]][k.first] += k.second;
            }
            swap(mp[i], mp[g[i][j]]);
        }
    }
    for(auto& i : ans) cout << i << "\n";
}

int main(){
	fastio;
	int t;
	t = 1;
	while(t--){
		solve();
	}
}
