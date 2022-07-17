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
	int v, lazy;
};

vector<st> segTree(2000001);
vector<int> vec(500001);

int init(int node, int s, int e) {
	if (s == e) return segTree[node].v = vec[s];
	int m{ (s + e) / 2 };
	return segTree[node].v = init(node * 2, s, m) ^ init(node * 2 + 1, m + 1, e);
}

void update(int node, int s, int e, int l, int r, int v) {
	if (segTree[node].lazy != 0) {
		if ((e - s + 1) & 1) segTree[node].v ^= segTree[node].lazy;
		if (s != e) {
			segTree[node * 2].lazy ^= segTree[node].lazy;
			segTree[node * 2 + 1].lazy ^= segTree[node].lazy;
		}
		segTree[node].lazy = 0;
	}
	if (r < s || e < l) return;
	if (l <= s && e <= r) {
		if ((e - s + 1) & 1) segTree[node].v ^= v;
		if (s != e) {
			segTree[node * 2].lazy ^= v;
			segTree[node * 2 + 1].lazy ^= v;
		}
		return;
	}
	int m{ (s + e) / 2 };
	update(node * 2, s, m, l, r, v);
	update(node * 2 + 1, m + 1, e, l, r, v);
	segTree[node].v = segTree[node * 2].v ^ segTree[node * 2 + 1].v;
}

int f(int node, int s, int e, int l, int r) {
	if (segTree[node].lazy != 0) {
		if ((e - s + 1) & 1) segTree[node].v ^= segTree[node].lazy;
		if (s != e) {
			segTree[node * 2].lazy ^= segTree[node].lazy;
			segTree[node * 2 + 1].lazy ^= segTree[node].lazy;
		}
		segTree[node].lazy = 0;
	}
	if (r < s || e < l) return 0;
	if (l <= s && e <= r) return segTree[node].v;
	int m{ (s + e) / 2 };
	return f(node * 2, s, m, l, r) ^ f(node * 2 + 1, m + 1, e, l, r);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i{ 0 }; i < n; ++i) {
		cin >> vec[i];
	}
	init(1, 0, n - 1);
	int t;
	cin >> t;
	while (t--) {
		int a, b, c, d;
		cin >> a >> b >> c;
		if (a == 1) {
			cin >> d;
			if (b > c) swap(b, c);
			update(1, 0, n - 1, b, c, d);
		}
		else if (a == 2) {
			if (b > c) swap(b, c);
			cout << f(1, 0, n - 1, b, c) << "\n";
		}
	}
}