#include <iostream>
#include <queue>
#include <string>
#include <stack>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <unordered_set>
#define vi vector<int>
#define pi pair<int, int>
#define ll long long
#define MAX 2147000000
#define MOD 998244353
using namespace std;

struct st {
	ll v, lazy;
};

vector<st> segTree(4000001);
vector<ll> vec(1000001);

ll init(int node, int s, int e) {
	if (s == e) return segTree[node].v = vec[s];
	int m{ (s + e) / 2 };
	return segTree[node].v = init(node * 2, s, m) + init(node * 2 + 1, m + 1, e);
}

void update(int node, int s, int e, int l, int r, ll diff) {
	if (segTree[node].lazy != 0) {
		segTree[node].v += segTree[node].lazy * (ll)(e - s + 1);
		if (s != e) {
			segTree[node * 2].lazy += segTree[node].lazy;
			segTree[node * 2 + 1].lazy += segTree[node].lazy;
		}
		segTree[node].lazy = 0;
	}
	if (r < s || e < l) return;
	if (l <= s && e <= r) {
		segTree[node].v += diff * (ll)(e-s+1);
		if (s != e) {
			segTree[node * 2].lazy += diff;
			segTree[node * 2 + 1].lazy += diff;
		}
		return;
	}
	int m{ (s + e) / 2 };
	update(node * 2, s, m, l, r, diff);
	update(node * 2 + 1, m + 1, e, l, r, diff);
	segTree[node].v = segTree[node * 2].v + segTree[node * 2 + 1].v;
}

ll sum(int node, int s, int e, int l, int r) {
	if (segTree[node].lazy != 0) {
		segTree[node].v += segTree[node].lazy * (ll)(e - s + 1);
		if (s != e) {
			segTree[node * 2].lazy += segTree[node].lazy;
			segTree[node * 2 + 1].lazy += segTree[node].lazy;
		}
		segTree[node].lazy = 0;
	}
	if (r < s || e < l) return 0;
	if (l <= s && e <= r) return segTree[node].v;
	int m{ (s + e) / 2 };
	return sum(node * 2, s, m, l, r) + sum(node * 2 + 1, m + 1, e, l, r);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i{ 0 }; i < n; ++i) {
		cin >> vec[i];
	}
	init(1, 0, n - 1);
	for (int i{ 0 }; i < m + k; ++i) {
		int a, b, c;
		cin >> a;
		if (a == 1) {
			ll d;
			cin >> b >> c >> d;
			update(1, 0, n - 1, b - 1, c - 1, d);
		}
		else if (a == 2) {
			cin >> b >> c;
			cout << sum(1, 0, n - 1, b - 1, c - 1) << "\n";
		}
	}
}