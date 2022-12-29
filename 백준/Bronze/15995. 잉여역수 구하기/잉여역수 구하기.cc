// 2022-12-30
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
    ll a, m;
    cin >> a >> m;
    ll x, y;
    exEuclid(a, m, x, y);
    cout << x;
}
