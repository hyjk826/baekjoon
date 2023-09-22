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
    int n, k;
    cin >> n >> k;
    vi S(n), H(n);
    for(auto& i : S) cin >> i;
    for(auto& i : H) cin >> i;
    vector<vi> dp(n, vi(101, -1));
    vi ch(n, -1);
    function<int(int,int)> f = [&](int a, int b){
        if(a == n) return 0;
        if(dp[a][b] != -1) return dp[a][b];
        for(int i{0}; i < n; ++i){
            if(ch[i] != -1) continue;
            ch[i] = 0;
            dp[a][b] = max(dp[a][b], f(a + 1, min(100, b + k)));
            ch[i] = -1;
            if(b >= H[a]){
                ch[i] = 1;
                dp[a][b] = max(dp[a][b], S[a] + f(a + 1, min(100, b - H[a] + k)));
                ch[i] = -1;
            }
        }
        return dp[a][b];
    };
    cout << f(0, 100);
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
