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

void solve(){
    int n; ll k;
    cin >> n >> k;
    vl vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    sort(vec.rbegin(), vec.rend());
    ll l{0}, r{(ll)1e12};
    ll ans{-1};
    while(l <= r){
        ll mid{(l + r) >> 1};
        ll sum{0};
        for(int i{0}; i < n; ++i){
            if(vec[i] < mid) break;
            sum += vec[i] - mid;
        }
        if(sum <= k){
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << ans << "\n";
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
