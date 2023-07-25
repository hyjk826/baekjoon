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

int f(char x){
	if(x <= '9') return x - '0';
	else return x - 'A' + 10;
}

void solve(){
	string s, t;
	cin >> s >> t;
	vi ans;
	ans.push_back(f(t[0]) ^ 2);
	ans.push_back(f(t[1]));
	for(int i{0}; i < (int)s.size(); ++i){
		ans.push_back(f(t[i + 2]) ^ f(s[i]) ^ ans[i]);
	}
	for(auto& i : ans){
		if(i <= 9) cout << i;
		else cout << char('A' + i - 10);
	}
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}