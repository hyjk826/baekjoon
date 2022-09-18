// 2022-09-18
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
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int main() {
	fastio;
	int n;
    cin >> n;
    ll ans{0};
    for(int i{0}; i < n; ++i){
        ll x, k;
        cin >> x >> k;
        ll a{1};
        while(k){
            ans += (k % 2) * a % MOD;
            ans %= MOD;
            k /= 2;
            a *= x;
            a %= MOD;
        }
    }
    cout << ans;
}
	

