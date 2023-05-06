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

ll lcm(ll a, ll b){
    return a / gcd(a, b) * b;
}

int main(){
	fastio;
    int n, k;
    cin >> n >> k;
    vi vec(k);
    for(int i{0}; i < k; ++i){
        cin >> vec[i];
    }
    int sum{0};
    int ans{n};
    for(int i{1}; i < (1 << k); ++i){
        ll l{1};
        for(int j{0}; j < k; ++j){
            if((i >> j) & 1){
                l = lcm(l, vec[j]);
                if(l > n) break;
            }
        }
        if(__builtin_popcount(i) & 1) ans -= n / l;
        else ans += n / l;
    }
    cout << ans;
}
