// 2022-12-24
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
    vs vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    vi ten(51);
    ten[0] = 1;
    int mod;
    cin >> mod;
    for(int i{1}; i <= 50; ++i){
        ten[i] = (ten[i - 1] * 10) % mod;
    }
    vp A(n);
    for(int i{0}; i < n; ++i){
        int sum = 0;
        for(auto& c : vec[i]){
            sum = (sum * 10 + (c - '0')) % mod;
        }
        A[i] = {sum, (int)vec[i].size()};
    }
    vector<vl> dp(mod, vl(1 << n, -1));
    function<ll(int,int)> f = [&](int a, int state){
        if(state == (1 << n) - 1) return (ll)(a % mod == 0);
        if(dp[a][state] != -1) return dp[a][state];
        dp[a][state] = 0;
        for(int i{0}; i < n; ++i){
            if(state & (1 << i)) continue;
            dp[a][state] += f((a * ten[A[i].second] + A[i].first) % mod, state | (1 << i));
        }
        return dp[a][state];
    };
    function<ll(ll, ll)> gcd = [&](ll a, ll b){
        if(b == 0) return a;
        return gcd(b, a % b);
    };
    ll x = f(0, 0);
    ll y{1};
    for(int i{1}; i <= n; ++i){
        y *= i;
    }
    ll g = gcd(x, y);
    cout << x / g << "/" << y / g;
}
