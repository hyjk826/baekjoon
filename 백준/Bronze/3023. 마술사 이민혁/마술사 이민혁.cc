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
    vector<vc> board(n, vc(m));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            cin >> board[i][j];
        }
    }
    vector<vc> board2(n * 2, vc(m * 2));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            board2[i][j] = board[i][j];
        }
    }
    for(int i{0}; i < n; ++i){
        for(int j{m}; j < 2 * m; ++j){
            board2[i][j] = board[i][2 * m - j - 1];
        }
    }
    for(int i{n}; i < 2 * n; ++i){
        for(int j{0}; j < m; ++j){
            board2[i][j] = board[2 * n - i - 1][j];
        }
    }
    for(int i{n}; i < 2 * n; ++i){
        for(int j{m}; j < 2 * m; ++j){
            board2[i][j] = board2[i][2 * m - j - 1];
        }
    }
    int x, y; 
    cin >> x >> y;
    x--; y--;
    if(board2[x][y] == '#') board2[x][y] = '.';
    else board2[x][y] = '#';
    for(int i{0}; i < n * 2; ++i){
        for(int j{0}; j < m * 2; ++j){
            cout << board2[i][j];
        }
        cout << "\n";
    }
}
