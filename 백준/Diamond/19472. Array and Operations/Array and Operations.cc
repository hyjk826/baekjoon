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
	ll mn, mx, sum, lazy, lazy2;
};

const int sz = (int)1e5 + 10;
st seg[sz * 4];
ll vec[sz];
int n, q;

void merge(int node, int l, int r){
    seg[node].mn = min(seg[l].mn, seg[r].mn);
    seg[node].mx = max(seg[l].mx, seg[r].mx);
    seg[node].sum = seg[l].sum + seg[r].sum;
}

void init(int node, int l, int r) {
	if (l == r) {
        seg[node] = {vec[l], vec[l], vec[l], 0, 0};
        return;
    }
	int m{ (l + r) >> 1 };
    init(node << 1, l, m);
    init(node << 1 | 1, m + 1, r);
    merge(node, node << 1, node << 1 | 1);
}

void propagate(int node, int l, int r){
	if (seg[node].lazy2 == 0) {
        seg[node].mn += seg[node].lazy;
        seg[node].mx += seg[node].lazy;
		seg[node].sum += seg[node].lazy * (ll)(r - l + 1);
		if (l ^ r) {
			seg[node << 1].lazy += seg[node].lazy;
			seg[node << 1 |1].lazy += seg[node].lazy;
		}
	}
    else{ 
        seg[node].mn = seg[node].mx = seg[node].lazy + seg[node].lazy2;
        seg[node].sum = (seg[node].lazy + seg[node].lazy2) * (ll)(r - l + 1);
        if(l ^ r){
            seg[node << 1].lazy = seg[node << 1 | 1].lazy = seg[node].lazy;
            seg[node << 1].lazy2 = seg[node << 1 | 1].lazy2 = seg[node].lazy2;
        }
    }
    seg[node].lazy = seg[node].lazy2 = 0;
}

void update(int node, int l, int r, int s, int e, ll diff) {
	propagate(node, l, r);
	if (e < l || r < s) return;
	if (s <= l && r <= e) {
		seg[node].lazy += diff;
		propagate(node, l, r);
		return;
	}
	int m{ (l + r) >> 1 };
	update(node << 1, l, m, s, e, diff);
	update(node << 1 | 1, m + 1, r, s, e, diff);
	merge(node, node << 1, node << 1 | 1);
}

void update2(int node, int l, int r, int s, int e) {
	propagate(node, l, r);
	if (e < l || r < s) return;
	if (s <= l && r <= e) {
        if((int)sqrt(seg[node].mn) == (int)sqrt(seg[node].mx)){
            seg[node].lazy2 = (int)sqrt(seg[node].mn);
		    propagate(node, l, r);
		    return;
        }		
        if(seg[node].mn + 1 == seg[node].mx){
            seg[node].lazy += (int)sqrt(seg[node].mn) - seg[node].mn;
            propagate(node, l, r);
            return;
        }
	}
    if(l == r) return;
	int m{ (l + r) >> 1 };
	update2(node << 1, l, m, s, e);
	update2(node << 1 | 1, m + 1, r, s, e);
	merge(node, node << 1, node << 1 | 1);
}


ll query(int node, int l, int r, int s, int e) {
	propagate(node, l, r);
	if (e < l || r < s) return 0;
	if (s <= l && r <= e) return seg[node].sum;
	int m{ (l + r) >> 1};
	return query(node << 1, l, m, s, e) + query(node << 1 | 1, m + 1, r, s, e);
}


int main(){
	fastio;
    int n, q;
    cin >> n >> q;
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    init(1, 0, n - 1);
    while(q--){
        int op, a, b, c;
        cin >> op;
        if(op == 1){
            cin >> a >> b >> c; a--; b--;
            update(1, 0, n - 1, a, b, c);            
        }
        else if(op == 2){
            cin >> a >> b; a--; b--;
            update2(1, 0, n - 1, a, b);
        }else{
            cin >> a >> b; a--; b--;
            cout << query(1, 0, n - 1, a, b) << "\n";
        }
    }
}
