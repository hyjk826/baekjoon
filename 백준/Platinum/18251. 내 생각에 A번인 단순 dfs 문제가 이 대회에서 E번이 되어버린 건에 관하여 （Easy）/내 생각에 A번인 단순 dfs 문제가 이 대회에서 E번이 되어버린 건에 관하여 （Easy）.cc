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
    vp A;
    vi vec(n + 1);
    for(int i{1}; i <= n; ++i) cin >> vec[i];
    int d{0};
    function<void(int,int)> dfs = [&](int cur, int depth){
        if(cur > n) return;
        d = max(d, depth);
        dfs(cur * 2, depth + 1);
        A.push_back({vec[cur], depth});
        dfs(cur * 2 + 1, depth + 1);
    };
    dfs(1, 0);
    ll ans{-LLONG_MAX};
    for(int i{0}; i <= d; ++i){
        for(int j{0}; j <= d; ++j){
            ll sum{0};
            for(auto& k : A){
                if(k.second >= i && k.second <= j){
                    sum += k.first;
                    ans = max(ans, sum);
                    if(sum < 0) sum = 0;
                }
            }
        }
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
