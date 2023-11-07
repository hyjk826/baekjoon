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
    vp vec;
    ll ans{0};
    for(int i{0}; i < n; ++i){
        int a, b;
        cin >> a >> b;
        if(a == 0) ans += b;
        else vec.push_back({a, b});
    }
    sort(vec.begin(), vec.end(), [&](pi& x, pi& y){
        return x.second + 1LL * y.first * x.second + y.second < y.second + 1LL * x.first * y.second + x.second;
    });
    ll cnt{0};
    for(auto& i : vec){
        ll k = 1LL * i.first * cnt + i.second;
        k %= 40000;
        ans += k;
        ans %= 40000;
        cnt += k;
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
