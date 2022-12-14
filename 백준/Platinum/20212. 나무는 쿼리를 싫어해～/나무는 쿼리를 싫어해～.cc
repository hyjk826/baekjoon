// 2022-12-14
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

struct Node{
    int l, r;
    ll v, lazy;
    Node(){
		l = r = -1;
		v = lazy = 0;
	};
};

vector<Node> seg(4000001);
int cnt = 1;

void update(int node, int s, int e, int l, int r, ll diff){
    if(seg[node].lazy != 0){
        seg[node].v += seg[node].lazy * (e - s + 1);
        if(s != e){
            if(seg[node].l == -1) seg[node].l = cnt++;
            if(seg[node].r == -1) seg[node].r = cnt++;
            seg[seg[node].l].lazy += seg[node].lazy;
            seg[seg[node].r].lazy += seg[node].lazy;
        }
        seg[node].lazy = 0;
    }
    if(r < s || e < l) return;
    if(l <= s && e <= r){
        seg[node].v += diff * (e - s + 1);
        if(s != e){
            if(seg[node].l == -1) seg[node].l = cnt++;
            if(seg[node].r == -1) seg[node].r = cnt++;
            seg[seg[node].l].lazy += diff;
            seg[seg[node].r].lazy += diff;
        }
        return;
    }
    int m{(s + e) / 2};
    if(seg[node].l == -1) seg[node].l = cnt++;
    if(seg[node].r == -1) seg[node].r = cnt++;
    update(seg[node].l, s, m, l, r, diff);
    update(seg[node].r, m + 1, e, l, r, diff);
    seg[node].v = seg[seg[node].l].v + seg[seg[node].r].v;
}


ll sum(int node, int s, int e, int l, int r){
    if(node == -1) return 0;
    if(seg[node].lazy != 0){
        seg[node].v += seg[node].lazy * (e - s + 1);
        if(s != e){
            if(seg[node].l == -1) seg[node].l = cnt++;
            if(seg[node].r == -1) seg[node].r = cnt++;
            seg[seg[node].l].lazy += seg[node].lazy;
            seg[seg[node].r].lazy += seg[node].lazy;
        }
        seg[node].lazy = 0;
    }
    if(r < s || e < l) return 0;
    if(l <= s && e <= r) return seg[node].v;
    int m{(s + e) / 2};
    return sum(seg[node].l, s, m, l, r) + sum(seg[node].r, m + 1, e, l, r);
}

struct st{
	int op, ord, id, l, r, k;
};


int main() {
	fastio;
	int n;
	cin >> n;
	int c{1};
	vector<st> query(n);
	vl ans(n);
	vi ch(n);
	for(int i{0}; i < n; ++i){
		int op, l, r, k;
		cin >> op >> l >> r >> k;
		if(op == 1) query[i] = {op, c++, i, l, r, k};
		else {
			query[i] = {op, k, i, l, r, k};
			ch[i] = 1;
		}
	}
	sort(query.begin(), query.end(), [&](st x, st y){
		if(x.ord == y.ord) return x.op < y.op;
		return x.ord < y.ord;
	});
	for(int i{0}; i < n; ++i){
		if(query[i].op == 1) update(0, 1, (int)1e9, query[i].l, query[i].r, query[i].k);
		else ans[query[i].id] = sum(0, 1, (int)1e9, query[i].l, query[i].r);
	}
	for(int i{0}; i < n; ++i){
		if(ch[i]) cout << ans[i] << "\n";
	}
}
	