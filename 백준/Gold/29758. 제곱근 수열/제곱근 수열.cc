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

vector<vi> dp(1000, vi(500, -1));

void solve(){
    function<int(int,int)> f = [&](int a, int b){
        if(b == 1){
            if(a == 1) return 1;
            else return 0;
        }
        if(dp[a][b] != -1) return dp[a][b];
        dp[a][b] = 0;
        int k = (int)sqrt(a);
        if(k * k == a) k--;
        for(int i{k}; i >= 1; --i){
            dp[a][b] += f(i, b - 1);
        }
        return dp[a][b];
    };
    int n, l;
    cin >> n >> l;
    if(l == 1){
        if(n == 1) cout << 1 << "\n";
        else cout << 0 << "\n";
        return;
    }
    int k = (int)sqrt(n);
    if(k * k == n) k--;
    ll ans{0};
    for(int i{k}; i >= 1; --i){
        ans += f(i, l - 1);
    }
    cout << ans << "\n";
}

int main(){
	fastio;
	int T;
	cin >> T;
	while(T--){
		solve();
	}
}
