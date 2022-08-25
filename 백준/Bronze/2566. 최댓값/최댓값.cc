// 2022-08-25
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
    vector<vi> board(9, vi(9));
    for(int i{0}; i < 9; ++i){
        for(int j{0}; j < 9; ++j){
            cin >> board[i][j];
        }
    }
    int x{0}, y{0};
    for(int i{0}; i < 9; ++i){
        for(int j{0}; j < 9; ++j){
            if(board[i][j] > board[x][y]){
                x = i;
                y = j;
            }
        }
    }
    cout << board[x][y] << "\n" << x + 1 << " " << y + 1;
}

