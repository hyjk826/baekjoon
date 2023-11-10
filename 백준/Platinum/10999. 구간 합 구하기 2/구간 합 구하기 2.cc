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
    ll v, lazy;
    st(){
        lazy = 0;
    }
};

const int sz = (int)1e6 + 10;
st seg[sz * 4];
ll arr[sz];
ll n, a, b;

void init(int node, int l, int r){
    if(l == r) seg[node].v = arr[l];
    else{
        int mid{(l + r) >> 1};
        init(node << 1, l , mid);
        init(node << 1 | 1, mid + 1, r);
        seg[node].v = seg[node << 1].v + seg[node << 1 | 1].v;
    }
}

void propogate(int node, int l, int r){
    if(seg[node].lazy){
        seg[node].v += (r - l + 1) * seg[node].lazy;
        if(l ^ r){
            seg[node << 1].lazy += seg[node].lazy;
            seg[node << 1 | 1].lazy += seg[node].lazy;
        }
        seg[node].lazy = 0;
    }
}


void update(int node, int l, int r, int s, int e, ll k){
    propogate(node, l, r);
    if(e < l || r < s) return;
    if(s <= l && r <= e){
        seg[node].lazy += k;
        propogate(node, l, r);
    }
    else{
        int mid{(l + r) >> 1};
        update(node << 1, l, mid, s, e, k);
        update(node << 1 | 1, mid + 1, r, s, e, k);
        seg[node].v = seg[node << 1].v + seg[node << 1 | 1].v;
    }
}

ll query(int node, int l, int r, int s, int e){
    propogate(node, l, r);
    if(r < s || e < l) return 0LL;
    if(s <= l && r <= e){
        return seg[node].v;
    }
    else{
        int mid{(l + r) >> 1};
        return query(node << 1, l, mid, s, e) + query(node << 1 | 1, mid + 1, r, s, e);
    }
}



void solve(){    
    cin >> n >> a >> b;
    for(int i{1}; i <= n; ++i){
        cin >> arr[i];
    }
    init(1, 1, n);
    for(int i{0}; i < a + b; ++i){
        int op;
        cin >> op;
        if(op == 1){
            int l, r;
            ll k;
            cin >> l >> r >> k;
            update(1, 1, n, l, r, k);
        }
        else{
            int l, r;
            cin >> l >> r;
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
