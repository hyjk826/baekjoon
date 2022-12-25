// 2022-12-24
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

ll exEuclid(ll a, ll b, ll &x, ll &y) {
	if (b == 0) {
		x = 1; y = 0;
		return a;
	}
	ll gcd = exEuclid(b, a%b, x, y);
	ll tmp = y;
	y = x - (a / b)*y;
	x = tmp;
	
	if (x <= 0) {
		x += b;
		y -= a;
	}
	return gcd;
}

int main(){
	fastio;
    int t;
    cin >> t;
    while(t--){
        ll b, a;
        cin >> b >> a;
        if(b == 1){
            cout << 2 << "\n";
            continue;
        }
        if(a == 1){
            if(b + 1 <= (ll)1e9) cout << b + 1 << "\n";
            else cout << "IMPOSSIBLE\n";
            continue;
        }
        ll x, y;
        ll g = exEuclid(a, b, x, y);
        if(g != 1 || x > (ll)1e9) cout << "IMPOSSIBLE\n";
        else cout << x << "\n";
    }
}
