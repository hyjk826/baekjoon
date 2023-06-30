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

ll f2(ll l, ll r){
    return 1LL * r * (r + 1) / 2 - 1LL * (l - 1) * l / 2;
}

ll f(ll n, ll k){
    int b = n;
    ll ret{0};
    while(1){
        ret += f2(k / ((k / b) + 1) + 1, b) * (k / b);
        b = k / ((k / b) + 1);       
        if(b == 0) break;
    }
	return ret;
}

void solve(){	
	ll n, k;
    cin >> n >> k;
    cout << n * k - f(n, k);
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}