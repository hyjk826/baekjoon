// 2022-12-26
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

vi vec(200001);
vector<vi> seg(800010);

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

int query(int node, int l, int r, int s, int e, int k){
    if(s > r || e < l) return 0;
    if(s <= l && r <= e){
        return upper_bound(seg[node].begin(), seg[node].end(), k) - seg[node].begin();
    }
    int m = (l + r) / 2;   
    return query(node * 2, l, m, s, e, k) + query(node * 2 + 1, m + 1, r, s, e, k);
}

int main(){
	fastio;
    int n, q, c;
    cin >> n >> q >> c;
    vi A(n + 1);
    for(int i{1}; i <= n; ++i){
        cin >> A[i];
    }
    vector<vi> g(n + 1);
    for(int i{0}; i < n - 1; ++i){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vi in(n + 1), out(n + 1);
    int cnt{-1};
    function<void(int, int)> dfs = [&](int cur, int pre){
        in[cur] = ++cnt;
        for(auto& i : g[cur]){
            if(i == pre) continue;
            dfs(i, cur);
        }
        out[cur] = cnt;
    };
    dfs(1, -1);
    for(int i{1}; i <= n; ++i){
        vec[in[i]] = A[i];
    }
    init(1, 0, n - 1);
    int ans{0};
    while(q--){
        int a, b;
        cin >> a >> b;
        ans += query(1, 0, n - 1, in[a], out[a], b);
        ans %= MOD;
    }
    cout << ans;
}
