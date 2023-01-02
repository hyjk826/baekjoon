// 2023-01-03
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
    ll l{0}, r{MAX};
    ll ans{-1};
    while(l <= r){
        ll m{(l + r) / 2};
        ll sum{0};
        ll a{5};
        while(a <= m){
            sum += m / a;
            a *= 5;
        }
        if(sum < n) {
            l = m + 1;
        }
        else{
            if(sum == n){
                ans = m;
            }
            r = m - 1;
        }
    }
    cout << ans;
}
