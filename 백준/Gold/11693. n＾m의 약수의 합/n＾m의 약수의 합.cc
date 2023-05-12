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

ll modpow(ll a, ll b){
    ll ans{1};
    while(b > 0){
        if(b & 1){
            ans *= a;
            ans %= MOD;
        }
        a *= a;
        b >>= 1;
        a %= MOD;
    }
    return ans;
}

int main(){
	fastio;
	ll n, m;
    cin >> n >> m;
    unordered_map<int, int> mp;
    for(int i{2}; i * i <= n; ++i){
        while(n % i == 0){
            mp[i]++;
            n /= i;
        }
    }
    if(n != 1) mp[n]++;
    ll ans{1};
    ll k{1};
    for(auto& i : mp){
        ans *= (modpow(i.first,  i.second * m + 1) - 1);
        ans %= MOD;
        k *= (i.first - 1);
        k %= MOD;
    }
    ans = (ans * modpow(k, MOD - 2)) % MOD;
    cout << ans;
}
