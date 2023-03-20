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
    ll k;
    cin >> k;
    ll ans{0};
    for(int i{0}; i < n; ++i){
        ll a;
        a = vec[i];
        while(a <= k){
            ans += k / a;
            if(a > k / vec[i]) break;
            a *= vec[i];
        }
    }
    cout << ans;
}
