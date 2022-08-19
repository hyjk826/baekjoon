#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <queue>
#include <map>
#include <cmath>
#include <cstring>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define MAX 2147000000
#define MOD 998244353LL
#define pi pair<int, int>
#define vi vector<int>
#define ll long long
using namespace std;

int main() {
	fastio;
	int n;
	ll x;
	cin >> n >> x;
	vector<ll> vec(n);
	for (int i{ 0 }; i < n; ++i) {
		cin >> vec[i];
	}
	sort(vec.begin(), vec.end());
	int k = lower_bound(vec.begin(), vec.end(), x) - vec.begin();
	int l{ 0 }, r{ k - 1 };
	int b{ 0 };
	while (l < r) {
		if ((vec[l] + vec[r]) * 2 >= x) {
			l++;
			r--;
			b++;
		}
		else {
			l++;
		}
	}
	cout << n - k + b + (k-b*2) / 3;
}