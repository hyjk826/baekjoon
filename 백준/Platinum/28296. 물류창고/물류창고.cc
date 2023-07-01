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
    int u, v, w;
};

const int sz = 100001;
int p[sz];
ll ans[sz];
unordered_map<int, int> mp[sz];

int find(int a){
    if(a == p[a]) return a;
    return p[a] = find(p[a]);
}

void merge(int a, int b, int k){
    a = find(a);
    b = find(b);
    if(a == b) return;
    if(mp[a].size() > mp[b].size()) swap(a, b);
    for(auto& i : mp[a]){
        if(mp[b].count(i.first)) {
            ans[i.first] += 1LL * i.second * mp[b][i.first] * k;
        }
        mp[b][i.first] += i.second;
    }
    mp[a].clear();
    p[a] = b;
}  

void solve(){
    int n, k, m;
    cin >> n >> k >> m;
    for(int i{1}; i <= n; ++i) p[i] = i;
    vi A(n + 1);
    for(int i{1}; i <= n; ++i){
        cin >> A[i];
        mp[i][A[i]]++;
    }
    vector<st> edge(m);
    for(int i{0}; i < m; ++i){
        cin >> edge[i].u >> edge[i].v >> edge[i].w;
    }
    sort(edge.begin(), edge.end(), [&](st& x, st& y){
        return x.w > y.w;
    });
    for(int i{0}; i < m; ++i){
        merge(edge[i].u, edge[i].v, edge[i].w);
    }
    for(int i{1}; i <= k; ++i) cout << ans[i] << "\n";
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}