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


void solve(){
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int ans{MAX};
	for(int i{0}; i <= c; ++i){
		int x = i * a;
		int y = (c - i) * a + b * d;
		ans = min(ans, max(x, y));
	}
	cout << ans << "\n";
}


int main(){
	fastio;
	int T;
	cin >> T;
	while(T--){
		solve();
	}
}