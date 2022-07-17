// 2022-07-17
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define pi pair<int, int>
#define pl pair<ll, ll>
#define vp vector<pi>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

struct st {
	int value, lazy;
};

vector<st> segTree(2000001);
vector<int> vec(500001);

void init(int node, int s, int e) {
	if (s == e){
        segTree[node].value = vec[s];
        return;
    }
    int m = (s + e) / 2;
	init(node * 2, s, m);
    init(node * 2 + 1, m + 1, e);
    segTree[node].value = segTree[node * 2].value ^ segTree[node * 2 + 1].value;
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

int f(int node, int s, int e, int l, int r) {
	if (segTree[node].lazy != 0) {
		if ((e - s + 1) & 1) segTree[node].value ^= segTree[node].lazy;
		if (s != e) {
			segTree[node * 2].lazy ^= segTree[node].lazy;
			segTree[node * 2 + 1].lazy ^= segTree[node].lazy;
		}
		segTree[node].lazy = 0;
	}
	if (r < s || e < l) return 0;
	if(l <= s && e <= r) return segTree[node].value;
	int m{ (s + e) / 2 };
	return f(node * 2, s, m, l, r) ^ f(node * 2 + 1, m + 1, e, l, r);
}

int main() {
	fastio;
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
			cin >> b >> c;
			cout << f(1, 0, n - 1, b, c) << "\n";
		}
	}
}