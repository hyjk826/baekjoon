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

int n, a, b;
const int sz = (int)1e6 + 10;
ll seg[sz * 4];
ll arr[sz];

void init(int node, int l, int r){
    if(l == r) seg[node] = arr[l];
    else{
        int mid{(l + r) >> 1};
        init(node << 1, l, mid);
        init(node << 1 | 1, mid + 1, r);
        seg[node] = seg[node << 1] + seg[node << 1 | 1];
    }
}

void update(int node, int l, int r, int idx, ll k){
    if(idx < l || idx > r) return;
    if(l == r) {
        seg[node] = k;
    }
    else{
        int mid{(l + r) >> 1};
        update(node << 1, l, mid, idx, k);
        update(node << 1 | 1, mid + 1, r, idx, k);
        seg[node] = seg[node << 1] + seg[node << 1 | 1];
    }
}

ll query(int node, int l, int r, int s, int e){
    if(r < s || e < l) return 0LL;
    if(s <= l && r <= e) return (ll)seg[node];
    int mid{(l + r) >> 1};
    return query(node << 1, l, mid, s, e) + query(node << 1 | 1, mid + 1, r, s, e);
}

void solve(){
	cin >> n >> a >> b;
    for(int i{1}; i <= n; ++i){
        cin >> arr[i];
    }
    init(1, 1, n);
    for(int i{0}; i < a + b; ++i){
        ll op, l, r;
        cin >> op >> l >> r;
        if(op == 1){
            update(1, 1, n, l, r);
        }
        else{
            cout << query(1, 1, n, l, r) << "\n";
        }
    }
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
