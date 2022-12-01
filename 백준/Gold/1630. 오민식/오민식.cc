// 2022-12-01
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
#define MOD 987654321
using namespace std;


int main() {
	fastio;
	vi prime((int)1e6 + 1);
    prime[1] = 1;
    for(ll i{2}; i <= (int)1e6; ++i){
        for(ll j{i * i}; j <= (int)1e6; j +=i){
            prime[j] = 1;
        }
    }
    int n;
    cin >> n;
    ll ans{1};
    for(int i{2}; i <= (int)1e6; ++i){
        if(prime[i]) continue;
        ll a = 1;
        while(a * i <= n){
            a *= i;
            ans *= i;
            ans %= MOD;
        }
    }
    cout << ans;
}
	
