// 2023-01-04
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
    ll n;
    cin >> n;
    ll ans{0};
    for(int i{2}; i <= n / 2; ++i){
        ll a = i;
        ans += n / i * i - i;
        ans %= 1000000;
    }
    cout << ans;
}
