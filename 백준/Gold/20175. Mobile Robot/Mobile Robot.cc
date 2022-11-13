// 2022-11-13
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

ll n, d;

ll f(vl& vec){
    ll mx{-LLONG_MAX};
    ll mn{LLONG_MAX};
    for(int i{0}; i < n; ++i){
        ll k = vec[i] - i * d;
        mx = max(mx, k);
        mn = min(mn, k);
    }
    return mx - mn;
}


int main() {
	fastio;    
    cin >> n >> d;
    vl vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    ll ans{LLONG_MAX};
    ans = min(ans, f(vec));
    reverse(vec.begin(), vec.end());
    ans = min(ans, f(vec));
    if(ans % 2 == 0) cout << ans / 2 << ".0";
    else cout << ans / 2 << ".5";
}
	

