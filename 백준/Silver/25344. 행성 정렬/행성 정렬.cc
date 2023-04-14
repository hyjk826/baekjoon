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
    if(a / g * b > (ll)1e9) return 1e9 + 1;
    return a / g * b;
}

int main(){
	fastio;
    int n;
    cin >> n;
    vi A(n - 2);
    for(int i{0}; i < n - 2; ++i){
        cin >> A[i];
    }
    int ans{A[0]};
    for(int i{1}; i < n - 2; ++i){
        ans = lcm(ans, A[i]);
    }
    cout << ans;
}
