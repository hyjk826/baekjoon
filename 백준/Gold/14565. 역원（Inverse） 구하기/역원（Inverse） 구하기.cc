// 2022-12-04
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


// ax + by = 1          
// 곱셈에 대한 역원 구하기 ax === 1 (mod b)
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

int main() {
	fastio;
	ll n, a;
    cin >> n >> a;
    ll x, y;
    if(exEuclid(a, n, x, y) != 1) x = -1;
    cout << n - a << " " << x;
}
	
