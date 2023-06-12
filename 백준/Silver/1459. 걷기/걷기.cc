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
    ll x, y, w, s;
    cin >> x >> y >> w >> s;
    ll ans = w * (x + y);
    if((x + y) & 1) ans = min(ans, (max(x, y) - 1) * s + w);
    else ans = min(ans, max(x, y) * s);
    ll k = min(x, y);
    x -= k; 
    y -= k;
    ans = min(ans, s * k + (x + y) * w);
    cout << ans << "\n";
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
