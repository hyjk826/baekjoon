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

vector<vl> mul(vector<vl> A, vector<vl> B){
    vector<vl> ret(2, vl(2));
    for(int i{0}; i < 2; ++i){
        for(int j{0}; j < 2; ++j){
            for(int k{0}; k < 2; ++k){
                ret[i][j] += A[i][k] * B[k][j];
                ret[i][j] %= MOD;
            }
        }
    }
    return ret;
}

vector<vl> pow(vector<vl> A, ll p){
    vector<vl> ret(2, vl(2));
    ret[0][0] = ret[1][1] = 1;
    while(p){
        if(p & 1){
            ret = mul(ret, A);
        }
        A = mul(A, A);
        p >>= 1;
    }
    return ret;
}

ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

ll nthfibo(ll n){
    return pow({{1, 1}, {1, 0}}, n - 1)[0][0];
}

int main(){
	fastio;
    ll n;
    cin >> n;
    ll a = nthfibo(n);
    ll b = nthfibo(n + 1);
    a *= a;
    b *= b;
    a %= MOD;
    b %= MOD;
    ll ans = b - a;
    if(n & 1) ans++;
    else ans--;
    cout << (ans + MOD) % MOD;
}
