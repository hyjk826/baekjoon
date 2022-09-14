// 2022-09-14
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
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

ll f(ll n){
    ll ret{0};
    n++;
    for(int i{0}; i < 60; ++i){
        ll k = (1LL << (i + 1));
        ll r = n % k;
        ret += n / k * (k / 2);
        ret += max(0LL, r - k / 2);
    }
    return ret;
}

int main() {
	fastio;
    ll a, b;
    cin >> a >> b;
    cout << f(b) - f(a - 1);
}
	

