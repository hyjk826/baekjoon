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
    ll n;
    while(cin >> n){
        if(n == 0) break;
        int ans{0};
        for(ll i{1}; i * i <= n * n; ++i){
            if((n * n) % i == 0){
                ll a = i;
                ll b = (n * n) / i;
                if((a + b) & 1) continue;
                ll c = (a + b) / 2;
                ll d = (b - a) / 2;
                if(d > n) ans++;
            }
        }
        cout << ans << "\n";
    }
}
