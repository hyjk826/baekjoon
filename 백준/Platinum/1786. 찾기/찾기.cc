#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define vi vector<int>
#define pi pair<int, int>
#define ll long long
#define MAX 2147000000
#define MOD 998244353LL
using namespace std;

vector<int> table(string s) {
	int m{ (int)s.size() };
	vector<int> t(m);
	int j{ 0 };
	for (int i{ 1 }; i < m; ++i) {
		while (j && s[i] != s[j]) j = t[j - 1];
		if (s[i] == s[j]) t[i] = ++j;
	}
	return t;
}

vector<int> kmp(string s, string t) {
	vector<int> ans;
	vector<int> tb = table(t);
	int n{ (int)s.size() };
	int m{ (int)t.size() };
	int j{ 0 };
	for (int i{ 0 }; i < n; ++i) {
		while (j && s[i] != t[j]) j = tb[j - 1];
		if (s[i] == t[j]) {
			if (j == m - 1) {
				ans.push_back(i - m + 1);
				j = tb[j];
			}
			else j++;
		}
	}
	return ans;
}

int main() {
    fastio;
	string s, t;
	getline(cin, s);
	getline(cin, t);
	vector<int> ans = kmp(s, t);
	cout << ans.size() << "\n";
	for (auto& i : ans) {
		cout << i + 1 << " ";
	}
}