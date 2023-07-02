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
    int n, x;
    cin >> n >> x;
    int mn{MAX};
    vi vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    for(int i{0}; i < n - 1; ++i){
        mn = min(mn, vec[i] + vec[i + 1]);
    }
    cout << 1LL * mn * x;
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
