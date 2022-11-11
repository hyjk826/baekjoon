// 2022-11-12
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
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int main() {
	fastio;
    int n; ll m;
    cin >> n >> m;
    ll ans{0};
    vl vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    for(int i{1}; i < (1 << n); ++i){
        int cnt = __builtin_popcount(i);
        ll a{1};
        for(int j{0}; j < n; ++j){
            if((i >> j) & 1){
                a *= vec[j];
                if(a > m){
                    a = m + 1;
                    break;
                }
            }
        }
        if(cnt & 1) ans += m / a;
        else ans -= m / a;
    }
    cout << ans;
}
	

