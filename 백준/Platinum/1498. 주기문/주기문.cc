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

vi table(string s) {
	int m{ (int)s.size() };
	vector<int> t(m);
	int j{ 0 };
	for (int i{ 1 }; i < m; ++i) {
		while (j && s[i] != s[j]) j = t[j - 1];
		if (s[i] == s[j]) t[i] = ++j;
	}
	return t;
}


int main(){
	fastio;
	string str;
    cin >> str;
    auto A = table(str);
    for(int i{1}; i < (int)str.size(); ++i){
        if(A[i] == 0) continue;
        if((i + 1) % (i + 1 - A[i]) == 0){
            cout << i + 1 << " " << (i + 1) / (i + 1 - A[i]) << "\n";
        }
    }
}
