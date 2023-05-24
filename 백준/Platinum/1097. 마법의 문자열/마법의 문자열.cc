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

int table(string s) {
	int m{ (int)s.size() };
	vector<int> t(m);
	int j{ 0 };
	for (int i{ 1 }; i < m; ++i) {
		while (j && s[i] != s[j]) j = t[j - 1];
		if (s[i] == s[j]) t[i] = ++j;
	}
	return t.back();
}


int main(){
	fastio;
	int n;
    cin >> n;
    vs vec(n);
    int a = 0;
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
        a += (int)vec[i].size();
    }
    sort(vec.begin(), vec.end());
    int ans{0};
    int k;
    cin >> k;
    int cnt{0};
    vi A(n);
    iota(A.begin(), A.end(), 0);
    do{
        string tmp;
        for(auto& i : A) tmp += vec[i];
        int mn{1};
        auto b = table(tmp);
        if(b){
            if(a % (a - b) == 0) mn = a / (a -  b);
        }
        if(mn == k) ans++;
    }while(next_permutation(A.begin(), A.end()));
    cout << ans;
}
