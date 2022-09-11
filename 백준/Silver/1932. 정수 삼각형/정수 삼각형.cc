// 2022-09-11
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
        for(int j{0}; j < i + 1; ++j){
            cin >> board[i][j];
        }
    }
    for(int i{n - 2}; i >= 0; --i){
        for(int j{0}; j < i + 1; ++j){
            board[i][j] += max(board[i + 1][j], board[i + 1][j + 1]);
        }
    }
    cout << board[0][0];
}