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
    int n, m;
    cin >> n >> m;
    vi A(n), B(m);
    for(int i{0}; i < n; ++i){
        cin >> A[i];
    }
    for(int i{0}; i < m; ++i){
        cin >> B[i];
    }
    ll l{A[0]};
    for(int i{1}; i < n; ++i){
        l = lcm(l, A[i]);
    }
    ll g{B[0]};
    for(int i{1}; i < m; ++i){
        g = gcd(g, B[i]);
    }
    vi div;
    for(int i{1}; i * i <= g; ++i){
        if(g % i == 0){
            if(i * i == g) div.push_back(i);
            else{
                div.push_back(i);
                div.push_back(g / i);
            }
        }
    }
    int ans{0};
    for(auto& i : div){
        if(i % l == 0) ans++;
    }
    cout << ans;
}
