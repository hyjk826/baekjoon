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
	ll v, lazy;
    st() : v(MAX), lazy(-1){}
};

const int sz = (int)6e5 + 10;
vector<st> seg(sz * 4);
vector<ll> vec(sz);
int n, q;

void propogate(int node, int l, int r){
	if (seg[node].lazy != -1) {
		seg[node].v = seg[node].lazy;
		if (l != r) {
			seg[node << 1].lazy = seg[node].lazy;
			seg[node << 1 |1].lazy = seg[node].lazy;
		}
		seg[node].lazy = -1;
	}
}

void update(int node, int l, int r, int s, int e, ll diff) {
	propogate(node, l, r);
	if (e < l || r < s) return;
	if (s <= l && r <= e) {
		seg[node].lazy = diff;
		propogate(node, l, r);
		return;
	}
	int m{ (l + r) >> 1 };
	update(node * 2, l, m, s, e, diff);
	update(node * 2 + 1, m + 1, r, s, e, diff);
	seg[node].v = min(seg[node << 1].v,seg[node << 1 | 1].v);
}

ll query(int node, int l, int r, int s, int e) {
	propogate(node, l, r);
	if (e < l || r < s) return MAX;
	if (s <= l && r <= e) return seg[node].v;
	int m{ (l + r) >> 1};
	return min(query(node << 1, l, m, s, e), query(node << 1 | 1, m + 1, r, s, e));
}

int main(){
	fastio;
    int n, k;
    cin >> n >> k;
    vector<vp> floor(k + 1);
    vi A;
    for(int i{0}; i < n; ++i){
        int a, b,c;
        cin >> a >> b >> c;
        A.push_back(a); A.push_back(b);
        floor[c].push_back({a, b});
    }
    if(k == 1){
        cout << 0; return 0;
    }
    sort(A.begin(), A.end());
    A.erase(unique(A.begin(), A.end()), A.end());
    for(int i{1}; i <= k; ++i){
        for(auto& j : floor[i]){
            j.first = lower_bound(A.begin(), A.end(), j.first) - A.begin();
            j.second = lower_bound(A.begin(), A.end(), j.second) - A.begin();
        }
    }
    int sz = (int)A.size();
    for(auto& i : floor[1]){
        update(1, 0, sz - 1, i.first, i.second, 0);
    }
    struct st{
        int l, r, cnt;
    };
    int ans{MAX};
    for(int i{2}; i <= k; ++i){
        vector<st> temp;
        for(auto& j : floor[i]){
            int a = query(1, 0, sz - 1, j.first, j.second) + 1;
            temp.push_back({j.first, j.second, a});
            if(i == k) ans = min(ans, a);
        }
        for(auto& j : temp){
            update(1, 0, sz - 1, j.l, j.r, j.cnt);
        }
    }
    if(ans == MAX) cout << -1;
    else cout << ans;
}
