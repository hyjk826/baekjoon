// 2023-01-03
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
    const int sz = 8e5;
    vi A(sz + 1);
    A[1] = 1;
    for(int i{1}; i <= sz; ++i){
        if(A[i]){
            for(int j{2 * i}; j <+ sz; j += i){
                A[j] -= A[i];
            }
        }
    }
    ll l{0}, r{(ll)1e12};
    ll ans{0};
    while(l <= r){
        ll m{(l + r) / 2};
        ll sum{0};
        for(ll i{2}; i * i <= m; ++i){
            sum += (m / (i * i)) * -A[i];
        }
        if(sum >= n){
            ans = m;
            r = m - 1;
        }
        else l = m + 1;
    }
    cout << ans;
}
	
