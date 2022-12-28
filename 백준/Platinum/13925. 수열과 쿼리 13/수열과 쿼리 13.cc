// 2022-12-29
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
	ll v, a, b;
    st() : a(1), b(0) {}
};

vector<st> seg(400001);
vector<ll> vec(100001);

ll init(int node, int l, int r) {
	if (l == r) return seg[node].v = vec[l];
	int m{ (l + r) / 2 };
	return seg[node].v = (init(node * 2, l, m) + init(node * 2 + 1, m + 1, r)) % MOD;
}

void propogate(int node, int l, int r){
    if(seg[node].a == 1 && seg[node].b == 0) return;
    if(l != r){
        seg[node * 2].a = (seg[node * 2].a * seg[node].a) % MOD;
        seg[node * 2 + 1].a = (seg[node * 2 + 1].a * seg[node].a) % MOD;
        seg[node * 2].b = (seg[node].a * seg[node * 2].b + seg[node].b) % MOD;
        seg[node * 2 + 1].b = (seg[node].a * seg[node * 2 + 1].b + seg[node].b) % MOD;
    }
    seg[node].v = (seg[node].a * seg[node].v + (r - l + 1) * seg[node].b) % MOD;
    seg[node].a = 1;
    seg[node].b = 0;
}

void update(int node, int l, int r, int s, int e, ll mul, ll add) {
	propogate(node, l, r);
	if (e < l || r < s) return;
	if (s <= l && r <= e) {
		seg[node].a = mul % MOD;
        seg[node].b = add % MOD;
		propogate(node, l, r);
		return;
	}
	int m{ (l + r) / 2 };
	update(node * 2, l, m, s, e, mul, add);
	update(node * 2 + 1, m + 1, r, s, e, mul, add);
	seg[node].v = (seg[node * 2].v + seg[node * 2 + 1].v) % MOD;
}

ll query(int node, int l, int r, int s, int e) {
	propogate(node, l, r);
	if (e < l || r < s) return 0;
	if (s <= l && r <= e) return seg[node].v;
	int m{ (l + r) / 2 };
	return (query(node * 2, l, m, s, e) + query(node * 2 + 1, m + 1, r, s, e)) % MOD;
}

int main(){
	fastio;
    int n;
    cin >> n;
    for(int i{1}; i <= n; ++i){
        cin >> vec[i];
    }
    init(1, 1, n);
    int q;
    cin >> q;
    while(q--){
        ll op, a, b, c;
        cin >> op;
        if(op == 1){
            cin >> a >> b >> c;
            update(1, 1, n, a, b, 1, c);
        }
        else if(op == 2){
            cin >> a >> b >> c;
            update(1, 1, n, a, b, c, 0);
        }
        else if(op == 3){
            cin >> a >> b >> c;
            update(1, 1, n, a, b, 0, c);
        }
        else if(op == 4){
            cin >> a >> b;
            cout << query(1, 1, n, a, b) << "\n";
        }
    }
}
