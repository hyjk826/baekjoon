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

ll f2(ll n){
    ll k = sqrt(n);
    return (k * k == n);
}

bool f(ll a, ll b){
    return f2(a / gcd(a, b));
}

int main(){
	fastio;
    int n;
    cin >> n;
    vl vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    vl temp = vec;
    sort(temp.begin(), temp.end());
    bool ok = true;
    for(int i{0}; i < n; ++i){
        ok &= f(vec[i], temp[i]);
    }
    if(ok) cout << "YES";
    else cout << "NO";
}
