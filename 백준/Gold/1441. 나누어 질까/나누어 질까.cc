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

ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b){
    return a / gcd(a, b) * b;
}


int main(){
	fastio;
	int n, L, R;
    cin >> n >> L >> R;
    vi A(n);
    for(int i{0}; i < n; ++i){
        cin >> A[i];
    }
    ll ans{0};
    for(int i{1}; i < (1 << n); ++i){
        ll l{1};
        for(int j{0}; j < n; ++j){
            if((i >> j) & 1) l = lcm(l, A[j]);
            if(l > R) break;
        }
        if(__builtin_popcount(i) & 1) ans += R / l - (L - 1) / l;
        else ans -= R / l - (L - 1) / l;
    }
    cout << ans;
}
