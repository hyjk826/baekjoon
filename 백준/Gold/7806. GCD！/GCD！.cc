// 2022-11-30
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
    ll n, k;
	while(cin >> n >> k){
        map<ll, ll> mp;
        for(ll i{2}; i * i <= k; ++i){
            while(k % i == 0){
                mp[i]++;
                k /= i;
            }
        }
        if(k != 1) mp[k]++;
        ll ans{1};
        for(auto& i : mp){
            ll a = i.first;
            ll cnt{0};
            while(a <= n){
                cnt += n / a;
                a *= i.first;
            }
            for(int j{0}; j < min(cnt, i.second); ++j){
                ans *= i.first;
            }
        }
        cout << ans << "\n";
    }
}
	
