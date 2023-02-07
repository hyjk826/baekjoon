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
    int n;
    cin >> n;
    vi vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    function<ll(int)> f = [&](int x){
        ll ret{0};
        for(int i{1}; i < n; ++i){
            ret += abs(1LL * x * i - vec[i]);
        }
        return ret;
    };
    int l{0}, r{vec[n - 1]};
    while(r - l >= 3){
        int p = (l * 2 + r) / 3;
        int q = (l + r * 2) / 3;
        if(f(p) <= f(q)) r = q;
        else l = p;
    }
    ll ans{LLONG_MAX};
    for(int i{l}; i <= r; ++i){
        ans = min(ans, f(i));
    }
    cout << ans;
}
