// 2022-11-28
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
	int k, n;
    cin >> k >> n;
    vi vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    ll l{0}, r{(ll)1e12};
    ll ans{0};
    while(l <= r){
        ll m{(l + r) / 2};
        if(m == 0) break;
        ll sum{0};
        for(int i{0}; i < n; ++i){
            sum += vec[i] / m;
        }
        if(sum >= k){
            l = m + 1;
            ans = m;
        }
        else r = m - 1;
    }
    cout << ans;
}
	
