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
    for(auto& i : vec) cin >> i;
    ll ans{0};
    if(vec[0] > vec[2]) ans += (vec[0] - vec[2]) * 508;
    else ans += (vec[2] - vec[0]) * 108;
    if(vec[1] > vec[3]) ans += (vec[1] - vec[3]) * 212;
    else ans += (vec[3] - vec[1]) * 305;
    if(n == 5) ans += (vec[4]) * 707;
    ans *= 4763;
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
