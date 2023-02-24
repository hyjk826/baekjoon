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

struct st {
    vi cnt;
	int lazy;
    st(){
        lazy = 0;
        cnt.resize(32);
    }
};

const int sz = (int)1e5 + 10;
vector<st> seg(sz * 4);
vector<ll> vec(sz);
int n, q;

void propogate(int node, int l, int r){
	if (seg[node].lazy != 0) {
        vi ret(32);
        for(int i{0}; i < 32; ++i){
            ret[i ^ seg[node].lazy] += seg[node].cnt[i];
        }
		if (l != r) {
			seg[node * 2].lazy ^= seg[node].lazy;
			seg[node * 2 + 1].lazy ^= seg[node].lazy;
		}
		seg[node].cnt = ret;
		seg[node].lazy = 0;
	}
}

void update(int node, int l, int r, int s, int e, int diff) {
	propogate(node, l, r);
	if (e < l || r < s) return;
	if (s <= l && r <= e) {
		seg[node].lazy ^= diff;
		propogate(node, l, r);
		return;
	}
	int m{ (l + r) >> 1 };
	update(node * 2, l, m, s, e, diff);
	update(node * 2 + 1, m + 1, r, s, e, diff);
	for(int i{0}; i < 32; ++i){
        seg[node].cnt[i] = seg[node << 1].cnt[i] + seg[node << 1 | 1].cnt[i];
    }
}

int main(){
	fastio;
    int n, m;
    cin >> n >> m;
    vector<vp> g(n + 1);
    vi edge(n + 1);
    for(int i{0}; i < n - 1; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    vi p(n + 1);
    vi in(n + 1), out(n + 1);
    int pv{0};
    vi A(n + 1);
    function<void(int, int, int)> dfs = [&](int cur, int pre, int sum){
        in[cur] = ++pv;
        A[in[cur]] = sum;
        for(auto& i : g[cur]){
            if(i.first == pre) continue;
            p[i.first] = cur;
            edge[i.first] = i.second;
            dfs(i.first, cur, sum ^ i.second);
        }
        out[cur] = pv;
    };
    dfs(1, -1, 0);
    function<void(int,int,int)> init = [&](int node, int l, int r){
        if(l == r) seg[node].cnt[A[l]]++;
        else{
            int mid = (l + r) >> 1;
            init(node << 1, l, mid);
            init(node << 1 | 1, mid + 1, r);
            for(int i{0}; i < 32; ++i){
                seg[node].cnt[i] = seg[node << 1].cnt[i] + seg[node << 1 | 1].cnt[i];
            }
        }
    };
    init(1, 1, n);
    auto ret = seg[1].cnt;
    while(m--){
        int op, a, b, c;
        cin >> op;
        if(op == 1){
            cin >> a >> b >> c;
            if(p[a] == b) {
                update(1, 1, n, in[a], out[a], c ^ edge[a]);
                edge[a] = c;
            }
            else {
                update(1, 1, n, in[b], out[b], c ^ edge[b]);
                edge[b] = c;
            }
        }   
        else{
            cin >> c;
            auto vec = seg[1].cnt;
            ll ans{0};
            for(int i{0}; i < 32; ++i){
                ans += 1LL * vec[i] * vec[i ^ c];
            }
            cout << ans / 2 << "\n";
        }
    }
}
