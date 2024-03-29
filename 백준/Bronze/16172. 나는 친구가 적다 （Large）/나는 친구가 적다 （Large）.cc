// 2022-12-14
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define vs vector<string>
#define pi pair<int, int>
#define pl pair<ll, ll>
#define vp vector<pi>
#define vpl vector<pl>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
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
    string str;
    cin >> str;
    string s;
    for(int i{0}; i < (int)str.size(); ++i){
        if('0' <= str[i] && str[i] <= '9') continue;
        s += str[i];
    }
    string t; 
    cin >> t;
    vi r = kmp(s, t);
    if(r.empty()) cout << 0;
    else cout << 1;
}
	
