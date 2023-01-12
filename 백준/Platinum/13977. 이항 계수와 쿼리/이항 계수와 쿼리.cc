// 2022-07-31
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

vl fact(4000001);

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

ll f(int n, int m){
    ll r = fact[n];
    ll g = fact[m] * fact[n - m];
    g %= MOD;
    r *= modpow(g, MOD - 2);
    return r % MOD;
}

int main() {
	fastio;
    int t;
    cin >> t;
    fact[0] = 1;
    fact[1] = 1;
    for(int i{2}; i <= 4000000; ++i){
        fact[i] = fact[i - 1] * i;
        fact[i] %= MOD;
    }
    while(t--){
        int n, m;
        cin >> n >> m;
        cout << f(n, m) << "\n";
    }
}

