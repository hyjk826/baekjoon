// 2022-09-12
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define vs vector<string>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int main(){
    fastio;
    int n, m;
    cin >> n >> m;
    vector<vi> board(n + 1, vi(n + 1));
    for(int i{1}; i <= n; ++i){
        for(int j{1}; j <= n; ++j){
            cin >> board[i][j];
            board[i][j] += board[i - 1][j] + board[i][j - 1] - board[i - 1][j - 1];
        }
    }
    for(int i{0}; i < m; ++i){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << board[c][d] - board[c][b - 1] - board[a - 1][d] + board[a - 1][b - 1] << "\n";
    }
}