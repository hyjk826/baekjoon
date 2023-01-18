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

vector<int> segTree(400001);
vector<int> vec(100001);
int n;

int init(int node, int s, int e) {
	if (s == e) return segTree[node] = s;
	int m = (s + e) / 2;
	int l = init(node * 2, s, m);
	int r = init(node * 2 + 1, m + 1, e);
	if (vec[l] <= vec[r]) return segTree[node] = l;
	else return segTree[node] = r;
}

int idx(int node, int s, int e, int l, int r) {
	if (r < s || l > e) return -1;
	if (l <= s && e <= r) return segTree[node];
	int m{ (s + e) / 2 };
	int a{ idx(node * 2, s, m, l, r) };
	int b{ idx(node * 2 + 1, m + 1, e, l, r) };
	if (a == -1) return b;
	if (b == -1) return a;
	if (vec[a] <= vec[b]) return a;
	else return b;
}

ll area(int s, int e) {
	int x = idx(1, 0, n - 1, s, e);
	ll r = 1LL * vec[x] * (ll)(e - s + 1);
	if (s <= x - 1) {
		ll a = area(s, x - 1);
		r = max(r, a);
	}
	if (e >= x + 1) {
		ll b = area(x + 1, e);
		r = max(r, b);
	}
	return r;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while (1) {
		cin >> n;
		if (n == 0) break;
		for (int i{ 0 }; i < n; ++i) {
			cin >> vec[i];
		}
		init(1, 0, n - 1);
		cout << area(0, n - 1) << "\n";
	}
}