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

int board[4001][4001];
int dp[801][4001];

int C(int a, int b){
    return (board[b][b] - board[a - 1][b] - board[b][a - 1] + board[a - 1][a - 1]) / 2;
}

void f(int t, int l, int r, int s, int e){
    if(l > r) return;
    int mid = (l + r) >> 1;
    int k;
    for(int i{s}; i <= e && i + 1 <= mid; ++i){
        ll a = dp[t - 1][i] + C(i + 1, mid);
        if(dp[t][mid] > a){
            dp[t][mid] = a;
            k = i;
        }
    }
    f(t, l, mid - 1, s, k);
    f(t, mid + 1, r, k, e);
}


void solve(){
    int n, k;
    cin >> n >> k;
    for(int i{1}; i <= n; ++i){
        for(int j{1}; j <= n; ++j){
            cin >> board[i][j];
            board[i][j] += board[i][j - 1] + board[i - 1][j] - board[i - 1][j - 1];
        }
    }
    for(int i{0}; i <= k; ++i){
        for(int j{0}; j <= n; ++j){
            dp[i][j] = (int)1e9;
        }
    }
    for(int i{1}; i <= n; ++i){
        dp[1][i] = C(1, i);
    }
    for(int i{2}; i <= k; ++i){
        f(i, i, n, 1, n);
    }
    cout << dp[k][n] << "\n";
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}