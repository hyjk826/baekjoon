// 2022-12-15
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

int main() {
	fastio;
    ll a, b, c, d, p, s;
    cin >> a >> b >> c >> d >> p >> s;
    if(!((c - p) % b && (c - p) % b + p <= b)) c += s;
    ll x = (c + b - 1) / b;
    ll y = (a + d - 1) / d;
    if(x <= y) cout << "Victory!";
    else cout << "gg";
}   
	
