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

int dp[20][20][20][20];

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vc> board(n, vc(m));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            cin >> board[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    function<int(int,int,int,int)> f = [&](int x1, int y1, int x2, int y2){
        if(x1 < 0 || x1 > n - 1 || y1 < 0 || y1 > m - 1) return 0;
        if(x2 < 0 || x2 > n - 1 || y2 < 0 || y2 > m - 1) return 0;
        if(dp[x1][y1][x2][y2] != -1) return dp[x1][y1][x2][y2];
        int& ret = dp[x1][y1][x2][y2];
        ret = 0;
        set<int> st;
        for(int i{x1}; i <= x2; ++i){
            for(int j{y1}; j <= y2; ++j){
                if(board[i][j] == 'X') continue;
                st.insert(f(x1, y1, i - 1, j - 1) ^ f(x1, j + 1, i - 1, y2) ^ f(i + 1, y1, x2, j - 1) ^ f(i + 1, j + 1, x2, y2));
            }
        }
        for(int i{0};;++i){
            if(!st.count(i)) return ret = i;
        }
    };
    auto ans = f(0, 0, n - 1, m - 1);
    if(ans) cout << "First\n";
    else cout << "Second\n";
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}