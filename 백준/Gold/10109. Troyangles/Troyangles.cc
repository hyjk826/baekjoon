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
    vector<vc> board(n, vc(n));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < n; ++j){
            cin >> board[i][j];
        }
    }
    vector<vi> dp(n, vi(n, -1)); // ->
    function<int(int, int)> f = [&](int a, int b){
        if(a >= n || b >= n || board[a][b] == '.') return 0;
        if(dp[a][b] != -1) return dp[a][b];
        int& ret = dp[a][b];
        return ret = 1 + min({f(a + 1, b - 1), f(a + 1, b), f(a + 1, b + 1)});
    };
    int ans{0};
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < n; ++j){
            ans += f(i, j);
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
