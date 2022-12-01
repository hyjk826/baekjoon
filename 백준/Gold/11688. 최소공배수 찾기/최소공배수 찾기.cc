// 2022-12-01
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
    ll g = gcd(a, b);
    return a / g * b;
}



int main() {
	fastio;
	ll a, b, l;
    cin >> a >> b >> l;
    ll x = lcm(a, b);
    map<int, int> mp1;
    for(ll i{2}; i * i <= l; ++i){
        while(l % i == 0){
            l /= i;
            mp1[i]++;
        }
    }
    if(l != 1) mp1[l]++;
    map<int, int> mp2;
    for(ll i{2}; i * i <= x; ++i){
        while(x % i == 0){
            x /= i;
            mp2[i]++;
        }
    }
    if(x != 1) mp2[x]++;
    for(auto& i : mp2){
        if(!mp1.count(i.first) || i.second > mp1[i.first]){
            cout << -1;
            return 0;
        }
    }
    ll ans{1};
    for(auto& i : mp1){
        if(i.second == mp2[i.first]) continue;
        for(int j{0}; j < i.second; ++j){
            ans *= i.first;
        }
    }
    cout << ans;
}
	
