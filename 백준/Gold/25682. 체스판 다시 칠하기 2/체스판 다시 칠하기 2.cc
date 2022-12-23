// 2022-12-24
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
    int n, m, k;
    cin >> n >> m >> k;
    vector<vc> board(n + 1, vc(m + 1));
    vector<vi> board2(n + 1, vi(m + 1));
    for(int i{1}; i <= n; ++i){
        for(int j{1}; j <= m; ++j){
            cin >> board[i][j];
            if((i + j) & 1){
                if(board[i][j] == 'B') board2[i][j] = 1;
            } 
            else{
                if(board[i][j] == 'W') board2[i][j] = 1;
            }
        }
    }
    for(int i{1}; i <= n; ++i){
        for(int j{1}; j <= m; ++j){
            board2[i][j] += board2[i - 1][j] + board2[i][j - 1] - board2[i - 1][j - 1];
        }
    }
    int ans{MAX};
    for(int i{0}; i + k <= n; ++i){
        for(int j{0}; j + k <= m; ++j){
            int a = board2[i + k][j + k] - board2[i][j + k] - board2[i + k][j] + board2[i][j];
            ans = min(ans, min(a, k * k - a));
        }
    }
    cout << ans;
}
