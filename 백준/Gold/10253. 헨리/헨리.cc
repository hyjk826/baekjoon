// 2023-01-12
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

ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

void f(ll& a, ll& b, ll& x){
    a = x * a - b;
    b = b * x;    
    ll g = gcd(a, b);
    if(a == 0) return;
    a /= g;
    b /= g;
}

int main(){
	fastio;
    int t;
    cin >> t;
    while(t--){
        ll a, b;
        cin >> a >> b;
        ll ans;
        while(a){
            ans = (b + a - 1) / a;
            f(a, b, ans);
        }
        cout << ans << "\n";
    }
}
