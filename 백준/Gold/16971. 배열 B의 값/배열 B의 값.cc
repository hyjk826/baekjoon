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
	int n, m;
    cin >> n >> m;
    vector<vi> board(n, vi(m));
    int ans{0};
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            cin >> board[i][j];
            if(i == 0 && j == 0) ans += board[i][j];
            else if(i == 0 && j == m - 1) ans += board[i][j];
            else if(i == n - 1 && j == 0) ans += board[i][j];
            else if(i == n - 1 && j == m - 1) ans += board[i][j];
            else if(i == 0 || i == n - 1 || j == 0 || j == m - 1) ans += 2 * board[i][j];
            else ans += 4 * board[i][j];
        }
    }
    int mx{0};
    for(int j{1}; j < m - 1; ++j){
        int cnt{0};
        for(int i{0}; i < n; ++i){
            if(i == 0 || i == n - 1){
                cnt += board[i][0] - board[i][j];
            }
            else cnt += 2 * (board[i][0] - board[i][j]);
        }
        mx = max(mx, cnt);
    }
    for(int j{1}; j < m - 1; ++j){
        int cnt{0};
        for(int i{0}; i < n; ++i){
            if(i == 0 || i == n - 1){
                cnt += board[i][m - 1] - board[i][j];
            }
            else cnt += 2 * (board[i][m - 1] - board[i][j]);
        }
        mx = max(mx, cnt);
    }
    for(int i{1}; i < n - 1; ++i){
        int cnt{0};
        for(int j{0}; j < m; ++j){
            if(j == 0 || j == m - 1) cnt += board[0][j] - board[i][j];
            else cnt += 2 * (board[0][j] - board[i][j]);
        }
        
        mx = max(mx, cnt);
    }
    for(int i{1}; i < n - 1; ++i){
        int cnt{0};
        for(int j{0}; j < m; ++j){
            if(j == 0 || j == m - 1) cnt += board[n - 1][j] - board[i][j];
            else cnt += 2 * (board[n - 1][j] - board[i][j]);
        }
        
        mx = max(mx, cnt);
    }
    ans += mx;
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
