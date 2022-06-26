// 2022-06-26
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

ll f(ll a, ll b){
    ll r{0};
    ll q = (a + 1) / (1LL << (b + 1));
    ll w = (a + 1) % (1LL << (b + 1));
    return q * (1LL << b) + max(0LL, w - (1LL << b));
}
int main(){
    fastio;
    ll a, b;
    cin  >> a >> b;
    ll ans{0};
    for(ll i{0}; i < 62; ++i){
        ll k = f(b, i) - f(a - 1 , i);
        if(k & 1) ans += (1LL << i);
    }
    cout << ans;
}
