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

vector<int> table(string& s) {
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
bool kmp(string& s, string& t) {
	vector<int> tb = table(t);
	int n{ (int)s.size() };
	int m{ (int)t.size() };
	int j{ 0 };
	for (int i{ 0 }; i < n; ++i) {
		while (j && s[i] != t[j]) j = tb[j - 1];
		if (s[i] == t[j]) {
			if (j == m - 1) {
				return true;
				j = tb[j];
			}
			else j++;
		}
	}
	return false;
}


int main(){
	fastio;
    int n;
    cin >> n;
    vi A(360000), B(360000);
    for(int i{0}; i < n; ++i){
        int a;
        cin >> a;
        A[a]++;
    }
    for(int i{0}; i < n; ++i){
        int a;
        cin >> a;
        B[a]++;
    }
    string s, t;
    for(int i{0}; i < 360000; ++i){
        s += char('0' + A[i]);
        t += char('0' + B[i]);
    }
    s += s;
    if(kmp(s, t)) cout << "possible";
    else cout << "impossible";
}
