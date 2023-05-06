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
            cin >> board[i][j];
        }
    }
    vector<vi> pmn(n, vi(m)), smn(n, vi(m));
    for(int j{0}; j < m; ++j){
        if(j == 0) pmn[0][0] = board[0][0];
        else pmn[0][j] = min(board[0][j], pmn[0][j - 1]);
    }
    for(int j{m - 1}; j >= 0; --j){
        if(j == m - 1) smn[0][m - 1] = board[0][m - 1];
        else smn[0][j] = min(board[0][j], smn[0][j + 1]);
    }
    for(int i{1}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            if(j == 0) board[i][j] += smn[i - 1][j + 1];
            else if(j == m - 1) board[i][j] += pmn[i - 1][j - 1];
            else board[i][j] += min(pmn[i - 1][j - 1], smn[i - 1][j + 1]);
        }
        for(int j{0}; j < m; ++j){
            if(j == 0) pmn[i][0] = board[i][0];
            else pmn[i][j] = min(board[i][j], pmn[i][j - 1]);
        }        
        for(int j{m - 1}; j >= 0; --j){
            if(j == m - 1) smn[i][m - 1] = board[i][m - 1];
            else smn[i][j] = min(board[i][j], smn[i][j + 1]);
        }   
    }
    cout << *min_element(board[n - 1].begin(), board[n - 1].end());
}
