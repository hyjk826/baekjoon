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
	int mn, lazy;
    st() : mn(MAX), lazy(0){}
};

const int sz = (int)1e5 + 10;
vector<st> seg(sz * 4);
vector<int> vec(sz);
int n, q;

int init(int node, int l, int r) {
	if (l == r) return seg[node].mn = vec[l];
	int m{ (l + r) >> 1 };
	return seg[node].mn = min(init(node << 1, l, m), init(node << 1 | 1, m + 1, r));
}

void propagate(int node, int l, int r){
	if (seg[node].lazy != 0) {
		seg[node].mn += seg[node].lazy;
		if (l != r) {
			seg[node << 1].lazy += seg[node].lazy;
			seg[node << 1 |1].lazy += seg[node].lazy;
		}
		seg[node].lazy = 0;
	}
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
	seg[node].mn = min(seg[node << 1].mn, seg[node << 1 | 1].mn);
}

int query(int node, int l, int r, int s, int e) {
	propagate(node, l, r);
	if (e < l || r < s) return MAX;
	if (s <= l && r <= e) return seg[node].mn;
	int m{ (l + r) >> 1};
	return min(query(node << 1, l, m, s, e),query(node << 1 | 1, m + 1, r, s, e));
}





int main(){
	fastio;
    string str;
    cin >> str;
    int n = (int)str.size();
    for(int i{0}; i < (int)str.size(); ++i){
        if(str[i] == '(') vec[i + 1] = 1;
        else vec[i + 1] = -1;
    }
    for(int i{1}; i <= (int)str.size(); ++i){
        vec[i] += vec[i - 1];
    }
    init(1, 0, n);
    cin >> q;
    int ans{0};
    while(q--){
        int l, r;
        cin >> l >> r;
        int k = query(1, 0, n, l - 1, l - 1);
        if(query(1, 0, n, l, r) >= k && query(1, 0, n, r, r) == k) {
            ans++;
        }
    }
    cout << ans;
}
