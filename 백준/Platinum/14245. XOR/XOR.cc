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
	int value, lazy;
};

vector<st> segTree(2000001);
vector<int> vec(500001);

int init(int node, int s, int e) {
	if (s == e) return segTree[node].value = vec[s];
	else return segTree[node].value = init(node * 2, s, (s + e) / 2) + init(node * 2 + 1, (s+e)/2 + 1, e);
}

void update(int node, int s, int e, int l, int r, int v) {
	if (segTree[node].lazy != 0) {
		if ((e - s + 1) & 1) segTree[node].value ^= segTree[node].lazy;
		if (s != e) {
			segTree[node * 2].lazy ^= segTree[node].lazy;
			segTree[node * 2 + 1].lazy ^= segTree[node].lazy;
		}
		segTree[node].lazy = 0;
	}
	if (r < s || e < l) return;
	if (l <= s && e <= r) {
		if ((e - s + 1) & 1) segTree[node].value ^= v;
		if (s != e) {
			segTree[node * 2].lazy ^= v;
			segTree[node * 2 + 1].lazy ^= v;
		}
		return;
	}

	int m{ (s + e) / 2 };
	update(node * 2, s, m, l, r, v);
	update(node * 2 + 1, m + 1, e, l, r, v);
	segTree[node].value = segTree[node * 2].value ^ segTree[node * 2 + 1].value;
}

void f(int node, int s, int e, int idx) {
	if (segTree[node].lazy != 0) {
		if ((e - s + 1) & 1) segTree[node].value ^= segTree[node].lazy;
		if (s != e) {
			segTree[node * 2].lazy ^= segTree[node].lazy;
			segTree[node * 2 + 1].lazy ^= segTree[node].lazy;
		}
		segTree[node].lazy = 0;
	}
	if (idx < s || e < idx) return;
	if (s == e) {
		cout << segTree[node].value << "\n";
		return;
	}
	int m{ (s + e) / 2 };
	f(node * 2, s, m, idx);
	f(node * 2 + 1, m + 1, e, idx);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n;
	for (int i{ 0 }; i < n; ++i) {
		cin >> vec[i];
	}
	init(1, 0, n - 1);
	cin >> m;
	while (m--) {
		int a, b, c, d;
		cin >> a;
		if (a == 1) {
			cin >> b >> c >> d;
			update(1, 0, n - 1, b, c, d);
		}
		else if (a == 2) {
			cin >> b;
			f(1, 0, n - 1, b);
		}
	}
}