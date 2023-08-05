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

struct st{
    int a, b, c;
};

void solve(){
    int n;
    cin >> n;
    vector<st> vec(n);
    for(auto& i : vec) cin >> i.a >> i.b >> i.c;
    ll l{1}, r{(ll)1e10};
    ll ans{-1};
    while(l <= r){
        ll mid{(l + r) >> 1};
        ll sum{0};
        for(auto& i : vec){
            if(i.a > mid) continue;
            sum += (min((ll)i.b, mid) - i.a) / i.c + 1;
        }
        if(sum & 1){
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    if(ans == -1) {
        cout << "NOTHING\n"; return;
    }
    int sum{0};
    for(auto& i : vec){
        if(i.a > ans || i.b < ans) continue;
        if((ans - i.a) % i.c == 0) sum++;
    }
    cout << ans << " " << sum << "\n";
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
