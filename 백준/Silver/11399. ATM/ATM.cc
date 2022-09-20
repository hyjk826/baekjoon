#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> vec;
	for (int i{ 0 }; i < n; ++i) {
		int a;
		cin >> a;
		vec.push_back(a);
	}
	sort(vec.begin(), vec.end());
	int sum{ 0 };
	for (int i{ 0 }; i < n; ++i) {
		sum += vec[i] * (n - i);
	}
	cout << sum;
}