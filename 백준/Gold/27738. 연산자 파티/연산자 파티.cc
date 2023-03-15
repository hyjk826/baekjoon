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

int main(){
	fastio;
    ll n;
    cin >> n;
    vl A(6);
    for(int i{0}; i < 6; ++i){
        cin >> A[i];
    }
    if(n <= (int)1e6){
        ll ans{0};
        for(ll i{1}; i <= n; ++i){
            if(i % A[0] == 0) ans += i;
            if(i % A[1] == 0) ans %= i;
            if(i % A[2] == 0) ans &= i;
            if(i % A[3] == 0) ans ^= i;
            if(i % A[4] == 0) ans |= i;    
            if(i % A[5] == 0) ans >>= i;
        }
        cout << ans; return 0;
    }
    ll q = n / A[5];
    ll w = n % A[5];
    ll ans{0};
    for(ll i{q * A[5] + 1}; i <= n; ++i){
        if(i % A[0] == 0) ans += i;
        if(i % A[1] == 0) ans %= i;
        if(i % A[2] == 0) ans &= i;
        if(i % A[3] == 0) ans ^= i;
        if(i % A[4] == 0) ans |= i;
    }
    cout << ans;
}
