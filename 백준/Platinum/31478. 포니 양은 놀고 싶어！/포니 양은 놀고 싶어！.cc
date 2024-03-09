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
using namespace std; 

ll modpow(ll a, ll b, ll MOD){
    ll ans{1};
    while(b > 0){
        if(b & 1){
            ans *= a;
            ans %= MOD;
        }
        a *= a;
        b >>= 1;
        a %= MOD;
    }
    return ans;
}

void solve(){
	ll a, b, c, k, l;
    cin >> a >> b >> c >> k >> l;
    ll x = modpow(a, modpow(b, c, 6), 7);
    ll y = modpow(b, c, 7) * modpow(a, 5, 7) % 7;
    bool ok1 = ((k + x) % 7 == l);
    bool ok2 = ((k + y) % 7 == l);
    if(ok1 && ok2) cout << 3 << "\n";
    else if(ok1) cout << 1 << "\n";
    else if(ok2) cout << 2 << "\n";
    else cout << 0 << "\n";
}


int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}