#include <iostream>
#include <queue>
#include <string>
#include <stack>
#include <map>
#include <algorithm>
#include <set>
#include <cmath>
#include <unordered_set>
#include <map>
#include <cstring>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define vi vector<int>
#define pi pair<int, int>
#define ll long long
#define MAX 2147000000
#define MOD 998244353LL
using namespace std;

int main() {
    fastio;
	int n;
	cin >> n;
	vector<int> vec(n);
	for (int i{ 0 }; i < n; ++i) {
		cin >> vec[i];
	}
	vector<int> ans(n);
	stack<int> st;
	for (int i{ n - 1 }; i >= 0; --i) {
		while (!st.empty() && st.top() <= vec[i]) {
			st.pop();
		}
		if (st.empty()) ans[i] = -1;
		else ans[i] = st.top();
		st.push(vec[i]);
	}
	for (auto& i : ans) {
		cout << i << " ";
	}
}