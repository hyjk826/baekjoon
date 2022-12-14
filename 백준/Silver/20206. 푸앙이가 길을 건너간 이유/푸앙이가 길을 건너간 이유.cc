// 2022-12-14
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
    ll a, b, c;
    cin >> a >> b >> c;
    ll x1, x2, y1, y2;
    cin >> x1 >> x2 >> y1 >> y2;
    ll r1, r2;
    if(a * b > 0){
        r1 = a * x1 + b * y1;
        r2 = a * x2 + b * y2;        
    }
    else{
        r1 = a * x1 + b * y2;
        r2 = a * x2 + b * y1;
    }
    if(r1 > r2) swap(r1, r2);
    if(r1 < -c && -c < r2) cout << "Poor";
    else cout << "Lucky";
}
	
