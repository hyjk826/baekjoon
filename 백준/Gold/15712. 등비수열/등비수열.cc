// 2022-09-21
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

ll a, r, n, m;

ll modpow(ll aa, ll b){
    ll ans{1};
    while(b > 0){
        if(b % 2){
            ans *= aa;
            ans %= m;
        }
        aa *= aa;
        b /= 2;
        aa %= m;
    }
    return ans;
}

ll f(ll x, ll y){
    if(x == y) return modpow(r, x);
    ll sz = y - x + 1;
    ll ret{0};
    if(sz & 1){
        ret += modpow(r, y);
        ret += f(x, y - 1);
    }   
    else{
        ll k = f(x, x + sz / 2 - 1);        
        ret += k + k * modpow(r, sz / 2);
    }
    return ret % m;
}

int main() {
	fastio;
    cin >> a >> r >> n >> m;
    cout << f(0, n - 1) * a % m;
}
	

