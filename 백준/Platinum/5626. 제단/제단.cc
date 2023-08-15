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

int dp[2][5010];

void solve(){
    int n;
    cin >> n;
    vi vec(n);
    for(int i{0}; i < n; ++i) {
        cin >> vec[i];
        if(vec[i] != -1) vec[i]++;
    }
    if(vec[0] > 1){
        cout << 0; return;
    }
    dp[0][1] = 1;
    for(int i{1}; i < n; ++i){
        memset(dp[1], 0, sizeof(dp[1]));
        if(vec[i] == -1){
            for(int j{1}; j <= 5001; ++j){
                dp[1][j] = (0LL + dp[0][j - 1] + dp[0][j] + dp[0][j + 1]) % MOD;
            }
        }
        else{
            for(int j{vec[i]}; j <= vec[i]; ++j){
                dp[1][j] = (0LL + dp[0][j - 1] + dp[0][j] + dp[0][j + 1]) % MOD;
            }
        }
        swap(dp[0], dp[1]);
    }
    cout << dp[0][1] << "\n";
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}