// 2023-01-16
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
    ll x, k;
    cin >> x >> k;
    vi vec(64);
    for(int i{0}; i < 40; ++i){
        if((x >> i) & 1) vec[i] = 1;
    }
    vi A;
    for(int i{0}; i < 63; ++i){
        if(vec[i] == 0) A.push_back(i);
    }
    vi B(64);
    for(int i{0}; i < 40; ++i){
        if((k >> i) & 1) B[A[i]] = 1;
    }
    ll ans{0};
    ll a{1};
    for(int i{0}; i < 63; ++i){
        if(B[i]) ans += a;
        a *= 2;
    }
    cout << ans;
}
