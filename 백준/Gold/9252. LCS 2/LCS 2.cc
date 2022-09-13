// 2022-09-14
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
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int main() {
	fastio;
    string s, t;
    cin >> s >> t;
    int n = (int)s.size();
    int m = (int)t.size();
    vector<vi> board(n + 1, vi(m + 1));
    for(int i{1}; i <= n; ++i){
        for(int j{1}; j <= m; ++j){
            if(s[i - 1] == t[j - 1]){
                board[i][j] = board[i - 1][j - 1] + 1;
            }
            else{
                board[i][j] = max(board[i - 1][j], board[i][j - 1]);
            }
        }
    }
    string ans;
    int x = n;
    int y = m;
    while(1){
        if(s[x - 1] == t[y - 1]){
            ans += s[x - 1];
            x--;
            y--;        
        }
        else{
            if(board[x - 1][y] == board[x][y]) x--;
            else y--;
        }
        if(x == 0 || y == 0) break;
    }
    cout << board[n][m] << "\n";
    reverse(ans.begin(), ans.end());
    cout << ans;
}
	

