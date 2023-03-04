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
    vector<vi> board(n + 1, vi(m + 1));
    for(int i{1}; i <= n; ++i){
        for(int j{1}; j <= m; ++j){
            board[i][j] = max(board[i - 1][j], board[i][j - 1]) + 1;
        }
    }
    if(board[n][m] > k) cout << "NO";
    else{
        cout << "YES\n";
        for(int i{1}; i <= n; ++i){
            for(int j{1}; j <= m; ++j){
                cout << board[i][j] << " ";
            }
            cout << "\n";
        }
    }
}
