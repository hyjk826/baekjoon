// 2022-11-16
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

vp minMaxSeg(200000);
vi vec(50000);

void init(int node, int l, int r){
    if(l == r) {
        minMaxSeg[node] = {vec[l], vec[r]};
        return;
    }
    int m = (l + r) / 2;
    init(node * 2, l, m);
    init(node * 2 + 1, m + 1, r);
    minMaxSeg[node].first = min(minMaxSeg[node * 2].first, minMaxSeg[node * 2 + 1].first);
    minMaxSeg[node].second = max(minMaxSeg[node * 2].second, minMaxSeg[node * 2 + 1].second);
}

pi query(int node, int l, int r, int s, int e){
    if(r < s || e < l) return {MAX, -MAX};
    if(s <= l && r <= e) return minMaxSeg[node];
    int m = (l + r) / 2;
    pi left = query(node * 2, l, m, s, e);
    pi right = query(node * 2 + 1, m + 1, r, s, e);
    return {min(left.first, right.first), max(left.second, right.second)};
}

int main() {
	fastio;
    int n, q;
    cin >> n >> q;
	for(int i{0}; i < n; ++i) cin >> vec[i];
	init(1, 0, n - 1);
	while(q--){
		int a, b;
		cin >> a >> b;
		a--; b--;
		auto k = query(1, 0, n - 1, a, b);
		cout << k.second - k.first << "\n";
	}
}
	

