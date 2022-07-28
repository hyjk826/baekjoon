#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#define pi pair<int, int>
#define vi vector<int>
#define ll long long
#define MAX 2147000000
using namespace std;

int xx[]{ 0,-1,0, 1 };
int yy[]{ -1,0,1,0 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> vec(n);
	vector<int> cnt(n);
	vector<int> v;
	v.push_back(-MAX);
	for (int i{ 0 }; i < n; ++i) {
		cin >> vec[i];
		if (v.back() < vec[i]) {
			v.push_back(vec[i]);
			cnt[i] = v.size() - 1;
		}
		else {
			auto it = lower_bound(v.begin(), v.end(), vec[i]);
			cnt[i] = it - v.begin();
			*it = vec[i];
		}
	}
	vector<int> ans;
	int idx{ (int)v.size() - 1 };
	for (int i{ n - 1 }; i >= 0; --i) {
		if (cnt[i] == idx) {
			ans.push_back(vec[i]);
			idx--;
		}
		if (idx == 0) break;
	}

	cout << v.size() - 1 << "\n";
	for (int i{ (int)ans.size() - 1 }; i >= 0; --i) {
		cout << ans[i] << " ";
	}
}