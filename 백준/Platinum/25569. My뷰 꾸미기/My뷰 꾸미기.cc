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


const int sz = 600001;

vl fact(sz);

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

void F(){
    fact[0] = 1;
    for(int i{1}; i < sz; ++i){
        fact[i] = fact[i - 1] * i;
        fact[i] %= MOD;
    }
}

ll C(int n ,int m){
    if(n < 0 || m < 0 || n < m) return 0;
    ll r = fact[n];
    ll g = fact[m] * fact[n - m] % MOD;
    return r * modpow(g, MOD - 2) % MOD;
}

ll H(int n, int m){
    return C(n + m - 1, m);
}

int main(){
	fastio;
    F();
    ll ans{1};
    int n;
    cin >> n;
    for(int i{0}; i < n; ++i){
        int a, b;
        cin >> a >> b;
        ans *= (C(a + b, a) - 1);
        ans %= MOD;
    }
    cout << ans;
}
