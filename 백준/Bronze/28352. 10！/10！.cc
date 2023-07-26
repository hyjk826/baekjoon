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
    ll f{1};
    for(int i{1}; i <= n; ++i){
        f *= i;
    }
    cout << f / (1LL * 7 * 24 * 60 * 60);
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
