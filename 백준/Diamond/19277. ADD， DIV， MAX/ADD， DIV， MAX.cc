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
    st() : mn(MAX), mx(-MAX), sum(0), lazy(0), lazy2(-LLONG_MAX){}
    st(ll a, ll b, ll c, ll d, ll e){
        mn = a; mx = b; sum = c; lazy = d; lazy2 = e;
    }
};

const int sz = (int)2e5 + 10;
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
        seg[node] = {vec[l], vec[l], vec[l], 0, -LLONG_MAX};
        return;
    }
	int m{ (l + r) >> 1 };
    init(node << 1, l, m);
    init(node << 1 | 1, m + 1, r);
    merge(node, node << 1, node << 1 | 1);
}

void propagate(int node, int l, int r){
    if(seg[node].lazy == 0 && seg[node].lazy2 == -LLONG_MAX) return;
	if (seg[node].lazy2 == -LLONG_MAX) {
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
    seg[node].lazy = 0; seg[node].lazy2 = -LLONG_MAX;
}

void update(int node, int l, int r, int s, int e, int diff) {
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

void update2(int node, int l, int r, int s, int e, double d) {
	propagate(node, l, r);
	if (e < l || r < s) return;
	if (s <= l && r <= e) {
        if(floor(seg[node].mn / d) == floor(seg[node].mx / d)){
            seg[node].lazy2 = floor(seg[node].mn / d);
		    propagate(node, l, r);
		    return;
        }		
        if(seg[node].mn + 1 == seg[node].mx){
            seg[node].lazy = floor(seg[node].mn / d) - seg[node].mn;
            propagate(node, l, r);
            return;
        }
	}
	int m{ (l + r) >> 1 };
	update2(node << 1, l, m, s, e, d);
	update2(node << 1 | 1, m + 1, r, s, e, d);
	merge(node, node << 1, node << 1 | 1);
}

int mxQuery(int node, int l, int r, int s, int e) {
	propagate(node, l, r);
	if (e < l || r < s) return -MAX;
	if (s <= l && r <= e) return seg[node].mx;
	int m{ (l + r) >> 1};
	return max(mxQuery(node << 1, l, m, s, e), mxQuery(node << 1 | 1, m + 1, r, s, e));
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
        cin >> op >> a >> b >> c;
        if(op == 0){
            update(1, 0, n - 1, a, b, c);            
        }
        else if(op == 1){
            update2(1, 0, n - 1, a, b, c);
        }else{
            cout << mxQuery(1, 0, n - 1, a, b) << "\n";
        }
    }
}
