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
    vector<vi> board(n, vi(3));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < 3; ++j){
            cin >> board[i][j];
        }
    }
    for(int i{1}; i < n; ++i){
        for(int j{0}; j < 3; ++j){
            if(j == 0){
                board[i][j] += min(board[i - 1][1], board[i - 1][2]);
            }
            else if(j == 1){
                board[i][j] += min(board[i - 1][0], board[i - 1][2]);
            }
            else{
                board[i][j] += min(board[i - 1][0], board[i - 1][1]);
            }
        }
    }
    cout << min({board[n - 1][0], board[n - 1][1], board[n - 1][2]});
}