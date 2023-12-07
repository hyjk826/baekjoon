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

int n;
ll k;
const int sz = (int)1e5 + 10;
vl vec(sz);
vector<vl> seg(sz * 4);

void init(int node, int l, int r){
    if(l == r) seg[node].push_back(vec[l]);
    else{
        int m = (l + r) / 2;
        init(node * 2, l, m);
        init(node * 2 + 1, m + 1, r);
        seg[node].resize(r - l + 1);
        merge(seg[node * 2].begin(), seg[node * 2].end(), seg[node * 2 + 1].begin(), seg[node * 2 + 1].end(), seg[node].begin());
    }
}

int query(int node, int l, int r, int s, int e, ll k){
    if(s > r || e < l) return 0;
    if(s <= l && r <= e){
        return upper_bound(seg[node].begin(), seg[node].end(), k) - seg[node].begin();
    }
    int m = (l + r) / 2;
    return query(node * 2, l, m, s, e, k) + query(node * 2 + 1, m + 1, r, s, e, k);
}

void solve(){
    cin >> n >> k;
    vector<vp> g(n + 1);
    for(int i{0}; i < n - 1; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    vi in(n + 1), out(n + 1);
    int pv{0};
    function<void(int, int, ll)> dfs = [&](int cur, int pre, ll w){
        in[cur] = ++pv;
        vec[in[cur]] = w;
        for(auto& i : g[cur]){
            if(i.first == pre) continue;
            dfs(i.first, cur, w + i.second);
        }
        out[cur] = pv;
    };
    
    dfs(1, 0, 0);
    init(1, 1, n);
    int ans{0};
    for(int i{1}; i <= n; ++i){
        ans = max(ans, query(1, 1, n, in[i], out[i], vec[in[i]] + k));
    }
    cout << ans << "\n";
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
