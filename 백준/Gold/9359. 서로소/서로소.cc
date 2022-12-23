// 2022-12-23
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
    for(int T{0}; T < t; ++T){
        ll a, b, n;
        cin >> a >> b >> n;
        vi div;
        for(ll i{2}; i * i <= n; ++i){
            if(n % i == 0){
                div.push_back(i);
                while(n % i == 0){
                    n /= i;
                }
            }
        }
        if(n != 1) div.push_back(n);
        ll ans{0};
        int k = (int)div.size();
        for(int i{0}; i < (1 << k); ++i){
            int y = __builtin_popcount(i);
            ll x{1};
            for(int j{0}; j < k; ++j){
                if((i >> j) & 1) x *= div[j];
            }
            if(y & 1) ans -= b / x - (a - 1) / x;
            else ans += b / x - (a - 1) / x;            
        }
        cout << "Case #" << T + 1 << ": ";
        cout << ans << "\n";
    }
}
