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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vi cnt(1001);
        for(int i{0}; i < n; ++i){
            int a;
            cin >> a;
            map<int, int> mp;
            for(int j{2}; j * j <= a; ++j){
                while(a % j == 0){
                    a /= j;
                    mp[j]++;
                }
            }
            if(a != 1) mp[a]++;            
            for(auto& j : mp){
                cnt[j.first] = max(cnt[j.first], j.second);
            }
        }
        ll ans{1};
        for(int i{1}; i <= 1000; ++i){
            if(cnt[i] == 0) continue;
            ans *= modpow(i, cnt[i]);
            ans %= MOD;
        }
        cout << ans << "\n";
    }
}
