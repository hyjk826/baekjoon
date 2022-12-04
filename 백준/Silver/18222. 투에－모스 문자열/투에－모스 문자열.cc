// 2022-12-04
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

int f(ll k){
    if(k == 1) return 0;
    ll a{1};
    while(a * 2 < k){
        a *= 2;
    }
    return f(k - a) ^ 1;
}


int main() {
	fastio;
	ll k;
    cin >> k;
    cout << f(k);
}
	
