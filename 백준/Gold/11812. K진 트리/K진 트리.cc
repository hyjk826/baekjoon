// 2023-01-13
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

ll n, k, q;

ll p(ll x){
    ll r = x % k;
    if(r == 1) x--;
    else if(r >= 2) x += (k - r);
    return x / k;
}

ll depth(ll x){
    ll ret{0};
    while(x != 1){
        x = p(x);
        ret++;
    }
    return ret;
}

int main(){
	fastio;
    cin >> n >> k >> q;
    while(q--){
        ll a, b;
        cin >> a >> b;
        if(k == 1){
            cout << abs(a - b) << "\n";
            continue;
        }
        int da = depth(a);
        int db = depth(b);
        if(da < db) swap(a, b);
        ll diff = abs(da - db);
        ll ans{diff};
        for(int i{0}; i < diff; ++i){
            a = p(a);
        }
        while(a != b){
            a = p(a);
            b = p(b);
            ans += 2;
        }
        cout << ans << "\n";
    }
}
