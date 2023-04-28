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

int main(){
	fastio;
    int n, m;
    cin >> n >> m;
    vector<vi> board(n + 2, vi(m + 2));
    for(int i{1}; i <= n; ++i){
        for(int j{1}; j <= m; ++j){
            cin >> board[i][j];
        }
    }
    int ans{0};
    for(int i{1}; i <= n; ++i){
        for(int j{1}; j <= m; ++j){
            ans += 2;
            ans += max(0, board[i][j] - board[i][j - 1]);
            ans += max(0, board[i][j] - board[i][j + 1]);
            ans += max(0, board[i][j] - board[i - 1][j]);
            ans += max(0, board[i][j] - board[i + 1][j]);
        }
    }
    cout << ans;
}
