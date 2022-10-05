// 2022-05-14
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int main(){
    fastio;
    ll n;
    cin >> n;
    ll k{0};
    ll ans{0};
    for(ll i{1}; i <= n; ++i){
        k += i * 2;
        ans += i * k;
        ans %= MOD;
    }
    ll b{1};
    for(int i{1}; i <= n; ++i){
        b *= i;
        b %= MOD;
    }
    cout << ans << " " << (b * b) % MOD;
}