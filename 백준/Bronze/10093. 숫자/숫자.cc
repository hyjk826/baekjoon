// 2022-07-31
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
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int main() {
	fastio;
    ll a, b;
    cin >> a >> b;
    if(a > b) swap(a, b);
    cout << max(b - a - 1, 0LL) << "\n";
    for(ll i{a + 1}; i < b; ++i){
        cout << i << " ";
    }
}

