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

int main(){
	fastio;
    ll a, d, q;
    cin >> a >> d >> q;
    while(q--){
        ll op, l, r;
        cin >> op >> l >> r;
        if(op == 1){
            cout << r * (a + a + (r - 1) * d) / 2 - (l - 1) * (a + a + (l - 2) * d) / 2 << "\n";
        }
        else{
            if(l == r) cout << a + (l - 1) * d << "\n";
            else cout << gcd(a + (l - 1) * d, d) << "\n";
        }
    }
}
