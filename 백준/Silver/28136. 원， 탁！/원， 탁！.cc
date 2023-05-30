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
    int n;
    cin >> n;
    vi vec(n);
    for(int i{0}; i < n; ++i) cin >> vec[i];
    int ans{0};
    for(int i{0}; i < n - 1; ++i){
        if(vec[i] >= vec[i + 1]) ans++;
    }
    if(vec.back() >= vec[0]) ans++;
    cout << ans;
}

int main(){
	fastio;
	int t;
	t = 1;
	while(t--){
		solve();
	}
}
