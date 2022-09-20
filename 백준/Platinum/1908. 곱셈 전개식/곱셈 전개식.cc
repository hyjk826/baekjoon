// 2022-08-18
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
#define MOD 10000
using namespace std;

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

ll f(ll a){
    ll r{0};
    ll k{1};
    for(int i{1}; k <= a; ++i){
        r += min(k * 10 - k, a - k + 1) * i;
        r %= MOD;
        k *= 10;
    }
    return r;
}

int main() {
	fastio;
    int n;
    cin >> n;
    ll ans{0};
    ans += modpow(2, n) - 1 + 2 * (n - 1) + n;
    ans %= MOD;
    ans += modpow(2, n - 1) * n;
    ans += f(n) * modpow(2, n - 1);
    ans += f(n) - 1;
    ans %= MOD;
    cout << ans;
}