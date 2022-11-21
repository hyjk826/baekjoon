// 2022-11-21
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
	int n, k;
    cin >> n >> k;
    ll l{1}, r{(ll)1e12};
    vi vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    ll ans{LLONG_MAX};
    while(l <= r){
        ll m{(l + r) / 2};
        ll sum{0};
        bool flag = false;
        for(int i{0}; i < n; ++i){
            sum += m / vec[i];
            if(sum >= k){
                flag = true;
                break;
            }
        }
        if(flag){
            r = m - 1;
            ans = m;
        }
        else l = m + 1;
    }
    cout << ans;
}
	

