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
	ll a, k;
    cin >> a >> k;
    ll b = k - a - 1;
    if(b < 0){
        cout << "NO"; return 0;
    }
    ll l{0}, r{a / 2};
    ll x{-1};
    while(l <= r){
        ll mid = (l + r) >> 1;
        ll X = mid * (a - mid);
        if(X == b){
            cout << "YES"; return 0;
        }
        if(X > b){
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    cout << "NO"; return 0;
}
