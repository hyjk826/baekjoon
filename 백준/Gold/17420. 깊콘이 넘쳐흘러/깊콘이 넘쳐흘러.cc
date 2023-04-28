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
    map<ll, vl> mp;
    vl A(n), B(n);
    for(int i{0}; i < n; ++i){
        cin >> A[i];
    }
    for(int i{0}; i < n; ++i){
        cin >> B[i];
    }
    for(int i{0}; i < n; ++i){
        mp[B[i]].push_back(A[i]);
    }
    ll mx{0};
    ll ans{0};
    for(auto& i : mp){
        ll m{0};
        ll a = max(mx, i.first);
        for(auto& j : i.second){
            ll k = max(0LL, (a - j + 29) / 30);
            ans += k;
            m = max(m, j + k * 30);     
        }
        mx = max(mx, m);
    }
    cout << ans;
}
