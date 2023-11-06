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
#define ull unsigned long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

void solve(){
	ll k, n;
    cin >> k >> n;
    vl vec(n);
    ll sum{0};
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
        sum += vec[i];
    }
    sort(vec.begin(), vec.end());
    ull res = 0;
    if(sum <= k) cout << 0 << "\n";
    else{
        ll l{0}, r{(ll)2e9};
        ll need = sum - k;
        ll ans{-1};
        while(l <= r){
            ll mid{(l + r) >> 1};
            ll sum{0};
            for(int i{0}; i < n; ++i){
                sum += min(vec[i], mid);
            }
            if(sum >= need){
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        vl tmp;
        ll sum{0};
        for(int i{0}; i < n; ++i){
            tmp.push_back(min(ans, vec[i]));
            sum += min(ans, vec[i]);
        }
        for(ll i{n - (sum - need)}; i < n; ++i){
            tmp[i]--;
        }
        for(auto& i : tmp){
            res += (ull)i * (ull)i;
        }
        cout << res << "\n";
    }

}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}