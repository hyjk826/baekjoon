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

vl div(ll n){
    vl ret;
    for(ll i{2}; i * i <= n; ++i){
        if(n % i == 0) {
            if(i * i == n) ret.push_back(i);
            else{
                ret.push_back(i);
                ret.push_back(n / i);
            }
        }
    }
    return ret;
}

int main(){
	fastio;
    unordered_map<ll, int> mp;
    mp[1] = 1;
    function<int(ll)> f = [&](ll n){
        if(mp.count(n)) return mp[n];
        vl d = div(n);
        if(d.size() == 0) return mp[n] = 1;
        bool ok = false;
        for(auto& i : d){
            ok |= (f(i) == 0);
        }
        return mp[n] = ok;
    };
    ll n;
    cin >> n;
    if(f(n)) cout << "koosaga";
    else cout << "cubelover";
}
