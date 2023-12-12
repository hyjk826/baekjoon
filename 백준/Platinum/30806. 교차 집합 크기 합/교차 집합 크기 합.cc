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
#define MOD 998244353
using namespace std; 

const int sz = (int)1e6 + 10;

vl fact(sz);

ll modpow(ll a, ll b){
    ll ans{1};
    while(b > 0){
        if(b % 2){
            ans *= a;
            ans %= MOD;
        }
        a *= a;
        b /= 2;
        a %= MOD;
    }
    return ans;
}

void F(){
    fact[0] = 1;
    for(int i{1}; i < sz; ++i){
        fact[i] = fact[i - 1] * i;
        fact[i] %= MOD;
    }
}

ll C(int n ,int m){
    if(n < 0 || m < 0 || n < m) return 0;
    ll r = fact[n];
    ll g = fact[m] * fact[n - m] % MOD;
    return r * modpow(g, MOD - 2) % MOD;
}

void solve(){
	int n;
    cin >> n;
    vector<vi> vec;
    vi A;
    for(int i{0}; i < n; ++i){
        int m;
        cin >> m;
        vi tmp(m);
        for(auto& j : tmp) {
            cin >> j;
            A.push_back(j);
        }
        vec.push_back(tmp);
    }
    sort(A.begin(), A.end());
    A.erase(unique(A.begin(), A.end()), A.end());
    vi cnt((int)A.size());
    for(auto& i : vec){
        for(auto& j : i){
            j = lower_bound(A.begin(), A.end(), j) - A.begin();
            cnt[j]++;
        }
    }
    vi ans(n + 1);
    for(int i{0}; i < (int)cnt.size(); ++i){
        for(int j{1}; j <= cnt[i]; ++j){
            ans[j] += C(cnt[i], j);
            ans[j] %= MOD;
        }
    }
    for(int i{1}; i <= n; ++i){
        cout << ans[i] << "\n";
    }
}

int main(){
	fastio;
    F();
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
