#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	map<string, string> mp;
	map<string, string> mp2;
	int idx{ 1 };

	for (int i{ 0 }; i < n; ++i) {
		string str;
		cin >> str;
		mp[str] = to_string(idx);
		mp2[to_string(idx)] = str;
		idx++;
	}

	vector<string> vec;
	for (int i{ 0 }; i < k; ++i) {
		string str;
		cin >> str;
		if (isdigit(str[0])) {
			vec.push_back(mp2[str]);
		}
		else {
			vec.push_back(mp[str]);
		}
	}

	for (auto i : vec) {
		cout << i << "\n";
	}
}