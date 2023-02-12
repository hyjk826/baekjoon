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
	int v, lazy;
    st() : v(0), lazy(-1){}
};

const int sz = (int)1e5 + 10;
vector<st> seg(sz * 4);
vector<int> vec(sz);
int n, t, q;

int init(int node, int l, int r) {
	if (l == r) return seg[node].v = 1;
	int m{ (l + r) >> 1 };
	return seg[node].v = (init(node * 2, l, m) | init(node * 2 + 1, m + 1, r));
}

void propogate(int node, int l, int r){
	if (seg[node].lazy != -1) {
		seg[node].v = (1 << seg[node].lazy);
		if (l != r) {
			seg[node * 2].lazy = seg[node].lazy;
			seg[node * 2 + 1].lazy = seg[node].lazy;
		}
		seg[node].lazy = -1;
	}
}

void update(int node, int l, int r, int s, int e, int val) {
	propogate(node, l, r);
	if (e < l || r < s) return;
	if (s <= l && r <= e) {
		seg[node].lazy = val;
		propogate(node, l, r);
		return;
	}
	int m{ (l + r) >> 1 };
	update(node * 2, l, m, s, e, val);
	update(node * 2 + 1, m + 1, r, s, e, val);
	seg[node].v = (seg[node * 2].v | seg[node * 2 + 1].v);
}

int query(int node, int l, int r, int s, int e) {
	propogate(node, l, r);
	if (e < l || r < s) return 0;
	if (s <= l && r <= e) return seg[node].v;
	int m{ (l + r) >> 1};
	return (query(node * 2, l, m, s, e) | query(node * 2 + 1, m + 1, r, s, e));
}

int main(){
	fastio;
    cin >> n >> t >> q;
    init(1, 1, n);
    while(q--){
        char op;
        int a, b, c;
        cin >> op;
        if(op == 'C'){
            cin >> a >> b >> c;
            c--;
            if(a > b) swap(a, b);
            update(1, 1, n, a, b, c);
        }
        else{
            cin >> a >> b;
            if(a > b) swap(a, b);
            cout << __builtin_popcount(query(1, 1, n, a, b)) << "\n";
        }
    }
}
