// 2022-12-12
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
    ll k, a, b;
    cin >> k >> a >> b;
    ll ans{0};
    if(a >= 0){
        ans += b / k + 1;
        if(a > 0) ans -= (a - 1) / k + 1;
    }
    else if(b <= 0){
        ans += (-a) / k + 1;
        if(b < 0) ans -= (-b - 1) / k + 1;
    }
    else{
        ans += b / k + (-a) / k + 1;
    }
    cout << ans;
}
	
