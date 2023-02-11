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
};

const int sz = (int)1e6 + 10;
vector<st> seg(sz * 4);
vector<ll> vec(sz);

ll init(int node, int l, int r) {
	if (l == r) return seg[node].v = vec[l];
	int m{ (l + r) / 2 };
	return seg[node].v = init(node * 2, l, m) + init(node * 2 + 1, m + 1, r);
}

void propogate(int node, int l, int r){
	if (seg[node].lazy != 0) {
		seg[node].v += seg[node].lazy * (ll)(r - l + 1);
		if (l != r) {
			seg[node * 2].lazy += seg[node].lazy;
			seg[node * 2 + 1].lazy += seg[node].lazy;
		}
		seg[node].lazy = 0;
	}
}

void update(int node, int l, int r, int s, int e, ll diff) {
	propogate(node, l, r);
	if (e < l || r < s) return;
	if (s <= l && r <= e) {
		seg[node].lazy += diff;
		propogate(node, l, r);
		return;
	}
	int m{ (l + r) / 2 };
	update(node * 2, l, m, s, e, diff);
	update(node * 2 + 1, m + 1, r, s, e, diff);
	seg[node].v = seg[node * 2].v + seg[node * 2 + 1].v;
}

ll query(int node, int l, int r, int s, int e) {
	propogate(node, l, r);
	if (e < l || r < s) return 0;
	if (s <= l && r <= e) return seg[node].v;
	int m{ (l + r) / 2 };
	return query(node * 2, l, m, s, e) + query(node * 2 + 1, m + 1, r, s, e);
}

int main(){
	fastio;
	int n, k;
	cin >> n >> k;
	for(int i{1}; i <= n; ++i){
		cin >> vec[i];
	}
	for(int i{1}; i <= n; ++i){
		int a;
		cin >> a;
		vec[i] = a - vec[i];
	}
	ll ans{0};
	for(int i{1}; i <= n; ++i){
		ll a = query(1, 1, (int)1e6, i, (int)1e6);
		if(a >= vec[i]) continue;
		a = vec[i] - a;
		int need = (a + k - 1) / k;
		int l = i;
		int r = i + k - 1;
		update(1, 1, (int)1e6, i, r, need);
		if(i - 1 >= 1) update(1, 1, (int)1e6, i - 1, i - 1, -k);
		ans += need;
	}
	cout << ans;
}
