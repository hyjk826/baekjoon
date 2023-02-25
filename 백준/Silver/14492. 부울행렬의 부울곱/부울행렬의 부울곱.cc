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
    int n;
    cin >> n;
    vector<vi> board(n, vi(n)), board2(n, vi(n));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < n; ++j){
            cin >> board[i][j];
        }
    }
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < n; ++j){
            cin >> board2[i][j];
        }
    }
    int ans{0};
    vector<vi> board3(n, vi(n));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < n; ++j){
            for(int k{0}; k < n; ++k){
                board3[i][j] |= (board[i][k] & board2[k][j]);
            }
            if(board3[i][j]) ans++;
        }
    }
    cout << ans;
}
