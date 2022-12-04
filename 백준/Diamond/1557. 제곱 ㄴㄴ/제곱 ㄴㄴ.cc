// 2022-12-04
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

int main() {
	fastio;
	ll n;
    cin >> n;
    vi A((int)1e6 + 1, 1);
    A[1] = 1;
    vi prime((int)1e6 + 1);
    for(int i = 2; i <= (int)1e6; i++) {
        if(prime[i]) continue;
        A[i] = -1;
        for(int j = 2 * i; j <= (int)1e6; j += i) {
            prime[j] = 1;
            if(j % (i * i) == 0) A[j] = 0;
            else A[j] *= -1;
        }
    }
    ll l{0}, r{MAX};
    int ans{0};
    while(l <= r){
        ll m{(l + r) / 2};
        ll sum{0};
        for(ll i{1}; i * i <= m; ++i){
            sum += (m / (i * i)) * A[i];
        }
        if(sum >= n){
            ans = m;
            r = m - 1;
        }
        else l = m + 1;
    }
    cout << ans;
}
	
