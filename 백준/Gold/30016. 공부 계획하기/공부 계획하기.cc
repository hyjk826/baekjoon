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
	int n, t;
    cin >> n >> t;
    vector<vi> board(n, vi(t + 1));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j <= t; ++j){
            cin >> board[i][j];
        }
    }
    vi d(t + 1);
    for(int i{0}; i <= t; ++i) cin >> d[i];
    vector<vi> dp(n, vi(t + 1, -1));
    vector<vi> pre(n, vi(t + 1, -1));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j <= t; ++j){
            if(i == 0) dp[i][j] = board[i][j];
            else{
                for(int k{0}; k <= j; ++k){
                    if(dp[i][j] < dp[i - 1][j - k] + board[i][k]){
                        dp[i][j] = dp[i - 1][j - k] + board[i][k];
                        pre[i][j] = k;
                    }
                }
            }
        }
    }
    int mx{-MAX};
    int time{0};
    for(int i{0}; i <= t; ++i){
        if(dp[n - 1][i] - d[i] > mx){
            mx = dp[n - 1][i] - d[i];
            time = i;
        }
    }
    cout << mx << '\n';
    vi ans;
    int cur{n - 1};
    while(cur != 0){
        ans.push_back(pre[cur][time]);
        time -= pre[cur][time];
        cur--;
    }
    ans.push_back(time);
    reverse(ans.begin(), ans.end());
    for(auto& i : ans) cout << i << " ";
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
