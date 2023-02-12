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

vector<int> table(vi& s) {
	int m{ (int)s.size() };
	vector<int> t(m);
	int j{ 0 };
	for (int i{ 1 }; i < m; ++i) {
		while (j && s[i] != s[j]) j = t[j - 1];
		if (s[i] == s[j]) t[i] = ++j;
	}
	return t;
}

bool kmp(vi& s, vi& t) {
	vector<int> ans;
	vector<int> tb = table(t);
	int n{ (int)s.size() };
	int m{ (int)t.size() };
	int j{ 0 };
	for (int i{ 0 }; i < n; ++i) {
		while (j && s[i] != t[j]) j = tb[j - 1];
		if (s[i] == t[j]) {
			if (j == m - 1) {
				return true;
			}
			else j++;
		}
	}
	return false;
}

int main(){
	fastio;
    int n, k;
    cin >> n >> k;
    vector<vi> A;
    for(int i{0}; i < n; ++i){
        int m;
        cin >> m;
        vi vec(m);
        for(int j{0}; j < m; ++j){
            cin >> vec[j];
        }
        A.push_back(vec);
    }
    bool ok = true;
    for(int i{0}; i <= (int)A[0].size() - k; ++i){
        ok = true;
        vi B(k);
        for(int j{0}; j < k; ++j){
            B[j] = A[0][i + j];
        }
        for(int j{1}; j < n; ++j){
            bool ok2 = false;
            ok2 |= kmp(A[j], B);
            reverse(B.begin(), B.end());
            ok2 |= kmp(A[j], B);
            reverse(B.begin(), B.end());
            if(!ok2) ok = false;
        }
        if(ok){
            cout << "YES"; return 0;
        }
    }
    cout << "NO";
}
