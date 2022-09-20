#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#define ll long long
#define pi pair<int, int>
#define veci vector<int>
#define MAX 2147000000
#define mod 1000000000
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<int> vec(n);
	for (int i{ 0 }; i < n; ++i) {
		cin >> vec[i];
	}
	int cnt{ 0 };
	int i{ n - 1 };
	while (k != 0) {
		if (k >= vec[i]) {
			cnt += k / vec[i];
			k %= vec[i];
		}
		i--;
	}
	cout << cnt;
}