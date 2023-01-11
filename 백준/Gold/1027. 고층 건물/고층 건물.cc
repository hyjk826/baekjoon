#include <iostream>
#include <queue>
#include <string>
#include <stack>
#include <map>
#include <algorithm>
#include <set>
#define vi vector<int>
#define pi pair<int, int>
#define ll long long
#define MAX 2147000000
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<double> vec(n);
	for (int i{ 0 }; i < n; ++i) {
		cin >> vec[i];
	}
	int ans{ 0 };
	for (int i{ 0 }; i < n; ++i) {
		double mn{ MAX * 1.0 }, mx{ -MAX * 1.0 };
		int cnt{ 0 };
		for (int j{ i-1 }; j >= 0; --j) {
			double k{ (vec[i] - vec[j]) / (i - j) };
			if (k < mn) cnt++;
			mn = min(mn, k);
		}
		for (int j{ i + 1 }; j < n; ++j) {
			double k{ (vec[i] - vec[j]) / (i - j) };
			if (k > mx) cnt++;
			mx = max(mx, k);
		}
		ans = max(ans, cnt);
	}
	cout << ans;
}