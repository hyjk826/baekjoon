// 2022-09-21
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
    ll n, k;
    while(cin >> n >> k){
        ll ans{0};
        ll d{0};
        while(n){
            ans += n;
            d += n;
            n = d / k;
            d %= k;
            if(n == 0 && d == 0) break;            
        }
        cout << ans << "\n";
    }
}
	

