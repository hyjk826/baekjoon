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
	int arr[4][4] = {
        {100, 70, 40, 0},
        {70, 50, 30, 0},
        {40, 30, 20, 0},
        {0, 0, 0, 0}
    };
    int n;
    cin >> n;
    vector<vc> board(n, vc(n));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < n; ++j){
            cin >> board[i][j];
            if(board[i][j] == 'F') board[i][j] = 'D';
        }
    }
    vector<vi> dp(n * n, vi((1 << n), -1));
    function<int(int,int)> f = [&](int a, int b){
        if(a >= n * n){
            if(a == n * n && b == 0) return 0;
            return -MAX;
        }
        int& ret = dp[a][b];
        if(ret != -1) return ret;
        ret = f(a + 1, b >> 1);
        if(!(b & 1)){
            if(a % n < n - 1 && !(b & 2)){
                int x = board[a / n][a % n] - 'A';
                int y = board[a / n][(a % n) + 1] - 'A';
                ret = max(ret, arr[x][y] + f(a + 2, b >> 2));
            }
            if(a / n <= n - 2){
                int x = board[a / n][a % n] - 'A';
                int y = board[a / n + 1][a % n] - 'A';
                ret = max(ret, arr[x][y] + f(a + 1, (b >> 1) | (1 << (n - 1))));
            }
        }
        return ret;
    };
    cout << f(0, 0);
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
