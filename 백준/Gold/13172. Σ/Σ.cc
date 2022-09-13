// 2022-09-13
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

ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

ll modpow(ll a, ll b){
    ll ans{1};
    while(b > 0){
        if(b % 2){
            ans *= a;
            ans %= MOD;
        }
        a *= a;
        b /= 2;
        a %= MOD;
    }
    return ans;
}


int main() {
	fastio;
    ll ans{0};
    int m;
    cin >> m;
    for(int i{0}; i < m; ++i){
        ll a, b;
        cin >> a >> b;
        ll g = gcd(a, b);
        a /= g;
        b /= g;
        ans += b * modpow(a, MOD - 2);
        ans %= MOD;
    }
    cout << ans;
}
	