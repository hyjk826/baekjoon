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

// t가 찾으려는 문자열
vector<int> kmp(vi& s, vi& t) {
	vector<int> ret((int)s.size());
	vector<int> tb = table(t);
	int n{ (int)s.size() };
	int m{ (int)t.size() };
	int j{ 0 };
	for (int i{ 0 }; i < n; ++i) {
		while (j && s[i] != t[j]) j = tb[j - 1];
		if (s[i] == t[j]) {
			if (j == m - 1) {
                ret[i] = j + 1;
				j = tb[j];
                continue;
			}
			else j++;
		}
        ret[i] = j;
	}
	return ret;
}

void solve(){
    int n, m;
    cin >> n >> m;
    vi A(n), B(m);
    for(auto& i : A) cin >> i;
    for(auto& i : B) cin >> i;
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());
    auto ret = kmp(A, B);
    int cnt{0};
    int s{0};
    for(int i{0}; i < n; ++i){
        if(ret[i]) cnt++;
        else{
            s ^= cnt;
            cnt = 0;
        }
    }
    if(cnt) s ^= cnt;
    if(s) cout << "First\n";
    else cout << "Second\n";
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
