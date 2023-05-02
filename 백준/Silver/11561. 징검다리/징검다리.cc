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
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        ll l{1}, r{(ll)2e9};
        ll ans{-1};
        while(l <= r){
            ll mid{(l + r) >> 1};
            if(mid * (mid + 1) / 2 <= n){
                ans = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        cout << ans << "\n";
    }
}
