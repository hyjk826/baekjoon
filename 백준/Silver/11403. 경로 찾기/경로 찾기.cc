// 2022-09-10
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
    int n;
    cin >> n;
    vector<vi> board(n, vi(n));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < n; ++j){
            cin >> board[i][j];
            if(board[i][j] == 0) board[i][j] = (int)1e9;
        }
    }
    for(int k{0}; k < n; ++k){
        for(int i{0}; i < n; ++i){
            for(int j{0}; j < n; ++j){
                board[i][j] = min(board[i][j], board[i][k] + board[k][j]);
            }
        }
    }
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < n; ++j){
            if(board[i][j] == (int)1e9) cout << 0 << " ";
            else cout << 1 << " ";
        }
        cout << "\n";
    }
}