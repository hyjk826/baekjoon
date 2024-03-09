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


void solve(){
	ll n;
    cin >> n;
    ll ans{1};
    for(int i{n}, j{1}; i >= 1; i -= 2, ++j){
        ans *= 1LL * i * (i - 1) / 2;    
        ans /= j;
    }
    cout << ans << "\n";
}


int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}