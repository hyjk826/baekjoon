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

ll f(ll n){
    ll a{10};
    ll sum{0};
    int cnt{1};
    while(1){
        if(n >= a - 1) sum += (a - a / 10) * cnt;
        else return sum + (n - a / 10 + 1) * cnt;
        a *= 10;
        cnt++;
    }
}


int main(){
	fastio;
    int n, k;
    cin >> n >> k;
    if(k > f(n)) cout << -1;
    else{
        ll l{1}, r{n};
        ll ans{-1};
        while(l <= r){
            ll m{(l + r) / 2};
            if(f(m) >= k){
                r = m - 1;
                ans = m;
            }
            else l = m + 1;
        }
        cout << to_string(ans)[k - (f(ans - 1) + 1)];
    }
}
