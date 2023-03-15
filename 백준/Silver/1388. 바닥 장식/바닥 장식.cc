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
    int ans{0};
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            if(board[i][j] == '-'){
                int y = j;
                while(y < m && board[i][y] == '-'){
                    board[i][y++] = 'A'; 
                }
                ans++;
            }
            else if(board[i][j] == '|'){
                int x = i;
                while(x < n && board[x][j] == '|'){
                    board[x++][j] = 'A';
                }
                ans++;
            }
        }
    }
    cout << ans;
}
