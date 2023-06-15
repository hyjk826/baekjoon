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

int dp[1 << 15][5];

void init(){
    dp[0][0] = 1;
    for(int i{1};;++i){
        if(i * i >= (1 << 15)) break;
        for(int j{0}; j <= 3; ++j){
            for(int k{(1 << 15) - 1 - (i * i)}; k >= 0; --k){
                dp[k + i * i][j + 1] += dp[k][j];
            }
        }
    }
}

void solve(int n){
    ll ans{0};
    for(int i{1}; i <= 4; ++i){
        ans += dp[n][i];
    }
    cout << ans << "\n";
}

int main(){
	fastio;
    init();
	while(1){
        int n;
        cin >> n;
        if(n == 0) break;
		solve(n);
	}
}
