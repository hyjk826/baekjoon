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

// t가 찾으려는 문자열
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

const ll p1 = 179, mod1 = 1e9 - 63;
const ll p2 = 917, mod2 = 1e9 + 7;

const int sz = 2e3 + 10;
ll ha1[sz], pw1[sz];
ll ha2[sz], pw2[sz];

void hashing(string& str){
    int n = (int)str.size();
    pw1[0] = pw2[0] = 1;
    for(int i{n - 1}; i >= 0; --i) ha1[i] = (ha1[i + 1] * p1 + str[i]) % mod1;
    for(int i{1}; i <= n; ++i) pw1[i] = pw1[i - 1] * p1 % mod1;
    for(int i{n - 1}; i >= 0; --i) ha2[i] = (ha2[i + 1] * p2 + str[i]) % mod2;
    for(int i{1}; i <= n; ++i) pw2[i] = pw2[i - 1] * p2 % mod2;
}


ll substr(int l, int r){
    ll r1 = ha1[l] - ha1[r + 1] * pw1[r - l + 1]; r1 %= mod1; if(r1 < 0) r1 += mod1;
    ll r2 = ha2[l] - ha2[r + 1] * pw2[r - l + 1]; r2 %= mod2; if(r2 < 0) r2 += mod2;
    return (r1 << 32 | r2);
}

int main(){
	fastio;
    string str, s, t;
    cin >> str >> s >> t;
    vi A = kmp(str, s);
    vi B = kmp(str, t);
	hashing(str);
	set<ll> st;
    for(auto& i : A){
		for(auto& j : B){
			int len = j + (int)t.size() - i;
			if(len < (int)s.size() || len < (int)t.size()) continue;
			st.insert(substr(i, j + (int)t.size() - 1));
		}
	}
    cout << st.size();
}
