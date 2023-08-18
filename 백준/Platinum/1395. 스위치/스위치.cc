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

vector<st> segTree(400001);

void update(int node, int s, int e, int l, int r) {
	if (segTree[node].lazy != 0) {
		if (segTree[node].lazy & 1) segTree[node].v = (e-s+1) - segTree[node].v;
		if (s != e) {
			segTree[node * 2].lazy += segTree[node].lazy;
			segTree[node * 2 + 1].lazy += segTree[node].lazy;
		}
		segTree[node].lazy = 0;
	}
	if (r < s || e < l) return;
	if (l <= s && e <= r) {
		segTree[node].v = (e - s + 1) - segTree[node].v;
		if (s != e) {
			segTree[node * 2].lazy += 1;
			segTree[node * 2 + 1].lazy += 1;
		}
		return;
	}
	int m{ (s + e) / 2 };
	update(node * 2, s, m, l, r);
	update(node * 2 + 1, m + 1, e, l, r);
	segTree[node].v = segTree[node * 2].v + segTree[node * 2 + 1].v;
}

int sum(int node, int s, int e, int l, int r) {
	if (segTree[node].lazy != 0) {
		if (segTree[node].lazy & 1) segTree[node].v = (e - s + 1) - segTree[node].v;
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
	int n, m;
	cin >> n >> m;
	for (int i{ 0 }; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 0) {
			update(1, 0, n - 1, b - 1, c - 1);
		}
		else if (a == 1) {
			cout << sum(1, 0, n - 1, b - 1, c - 1) << "\n";
		}
	}
}