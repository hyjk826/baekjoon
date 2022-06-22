// 2022-06-22
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

ll f(ll a){
    ll r{0};
    for(int i{1}; i <= 60; ++i){
        ll q = (a + 1) / (1LL << i);
        ll w = (a + 1) % (1LL << i);
        r += q * (1LL << (i - 1));
        r += max(0LL, w - (1LL << (i - 1)));
    }
    return r;
}

int main(){
    fastio;
	ll a, b;
    cin >> a >> b;
    cout << f(b) - f(a - 1);
}