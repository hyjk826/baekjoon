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
    vl vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    ll p, q, rr, s;
    cin >> p >> q >> rr >> s;
    ll ans{-1};
    ll l{1}, r{MAX};
    while(l <= r){
        ll mid{(l + r) / 2};
        ll sum{0};
        for(int i{0}; i < n; ++i){
            if(vec[i] > mid + rr) sum += vec[i] - p;
            else if(vec[i] < mid) sum += vec[i] + q;
            else sum += vec[i];
        }
        if(sum >= s){
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << ans;
}
