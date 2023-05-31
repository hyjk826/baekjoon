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

bool is_prime(ll n){
    for(ll i{2}; i * i <= n; ++i){
        if(n % i == 0) return false;
    }
    return true;
}

void solve(){
    vi div(1000001);
    for(int i{1}; i <= 1000000; ++i){
        for(int j{i}; j <= 1000000; j += i){
            div[j]++;
        }
    }
    ll n; cin >> n;
    ll ans{-1};
    if((ll)sqrt(n) * (ll)sqrt(n) == n){
        if(is_prime((ll)sqrt(n))){
            ans = (ll)sqrt(n);
        }
    }
    for(int i{1}; i <= 1000000; ++i){
        ll k = 1;
        bool ok = true;
        for(int j{0}; j < div[i]; ++j){
            if(k > (ll)1e18 / i){
                ok = false; break;
            }
            k *= i;
        }
        if(ok){
            if(k == n){
                if(ans == -1) ans = i;
                else ans = min(ans, (ll)i);
                break;
            }
        }
    }
    cout << ans;
}

int main(){
	fastio;
	int t;
	t = 1;
	while(t--){
		solve();
	}
}
