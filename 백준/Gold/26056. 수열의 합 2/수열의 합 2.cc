// 2023-01-22
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
    ll a, b;
    cin >> a >> b;
    function<ll(ll)> f = [&](ll x){
        ll ret{0};
        ll k = x;
        while(1){
            if(k == 0) break;
            ll c = x / k;
            ll d = x / (c + 1);
            if((k - d) & 1) {
                if(k & 1) ret -= c;
                else ret += c;
            }
            k = d;
        }
        return ret;
    };
    cout << f(b) - f(a - 1);
}
