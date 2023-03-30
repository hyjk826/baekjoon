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

struct seg{
    vi maxSeg;
    seg(int sz){
        maxSeg.resize(sz * 4);
    }
    void init(int node, int l, int r, vi& vec){
        if (l == r){
            maxSeg[node] = vec[l];
            return;
        }
        int m = (l + r) / 2;
        init(node * 2, l, m, vec);
        init(node * 2 + 1, m + 1, r, vec);
        maxSeg[node] = max(maxSeg[node * 2], maxSeg[node * 2 + 1]);
    }

    void update(int node, int l, int r, int idx, int value){
        if(l > idx || r < idx) return;
        if(l == r){
            maxSeg[node] = value;
        }
        else{
            int m = (l + r) / 2;
            update(node * 2, l, m, idx, value);
            update(node * 2 + 1, m + 1, r, idx, value);
            maxSeg[node] = max(maxSeg[node * 2], maxSeg[node * 2 + 1]);
        }
    }

    int query(int node, int l, int r, int s, int e){
        if (r < s || e < l)
            return -MAX;
        if (s <= l && r <= e)
            return maxSeg[node];
        int m = (l + r) / 2;
        int left = query(node * 2, l, m, s, e);
        int right = query(node * 2 + 1, m + 1, r, s, e);
        return max(left, right);
    }
};

int main(){
	fastio;
    int n;
    cin >> n;
    vi cost(n + 1);
    for(int i{1}; i <= n; ++i){
        cin >> cost[i];
    }
    vector<vi> g(n + 1);
    for(int i{0}; i < n - 1; ++i){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vi in(n + 1), out(n + 1);
    int pv{0};
    function<void(int,int)> dfs = [&](int cur, int pre){
        in[cur] = ++pv;
        for(auto& i : g[cur]){
            if(i == pre) continue;
            dfs(i, cur);
        }
        out[cur] = pv;
    };
    dfs(1, 0);
    seg s(n + 1);
    for(int i{1}; i <= n; ++i){
        s.update(1, 1, n, in[i], cost[i]);
    }
    ll ans{0};
    function<void(int,int)> dfs2 = [&](int cur, int pre){
        ll sum{0};
        for(auto& i : g[cur]){
            if(i == pre) continue;
            sum += s.query(1, 1, n, in[i], out[i]);
            dfs2(i, cur);
        }
        ll k{0};
        if(in[cur] - 1 >= 1) k = max(k, (ll)s.query(1, 1, n, 1, in[cur] - 1));        
        if(out[cur] + 1 <= n) k = max(k, (ll)s.query(1, 1, n, out[cur] + 1, n));
        sum += k;
        ans = max(ans, sum);
    };
    dfs2(1, 0);
    cout << ans;
}