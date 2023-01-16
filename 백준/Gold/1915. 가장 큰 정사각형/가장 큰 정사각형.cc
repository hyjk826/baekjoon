// 2023-01-16
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
    vector<vi> board(n, vi(m));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            char c;
            cin >> c;
            board[i][j] = c - '0';
        }
    }
    for(int i{1}; i < n; ++i){
        for(int j{1}; j < m; ++j){
            if(board[i][j] == 0) continue;
            board[i][j] = min({board[i - 1][j], board[i][j - 1], board[i - 1][j - 1]}) + 1;
        }
    }
    int ans{0};
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            ans = max(ans, board[i][j]);
        }
    }
    cout << ans * ans;
}