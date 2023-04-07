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

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}


int main(){
	fastio;
    int n;
    cin >> n;
    string s, t;
    for(int i{0}; i < n; ++i){
        char c;
        cin >> c;
        s += c;
    }
    for(int i{0}; i < n; ++i){
        char c;
        cin >> c;
        t += c;
    }
    for(int i{0}; i < n - 1; ++i){
        s += s[i];
    }
    auto ret = kmp(s, t);
    int k = (int)ret.size();
    int g = gcd(k, n);
    k /= g;
    n /= g;
    cout << k << "/" << n;
}
