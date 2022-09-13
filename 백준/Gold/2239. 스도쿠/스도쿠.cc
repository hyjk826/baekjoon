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

vector<vi> board(9, vi(9));
vp vec;

void dfs(int L){
    if(L == (int)vec.size()){
        for(int i{0}; i < 9; ++i){
            for(int j{0}; j < 9; ++j){
                cout << board[i][j];
            }
            cout << "\n";
        }
        exit(0);
    }
    else{
        int x = vec[L].first;
        int y = vec[L].second;
        for(int i{1}; i <= 9; ++i){
            bool flag = true;
            for(int j{0}; j < 9; ++j){
                if(board[x][j] == i){
                    flag = false;
                }
            }
            for(int j{0}; j < 9; ++j){
                if(board[j][y] == i){
                    flag = false;
                }
            }
            int xx = x / 3 * 3;
            int yy = y / 3 * 3;
            for(int j{xx}; j < xx + 3; ++j){
                for(int k{yy}; k < yy + 3; ++k){
                    if(board[j][k] == i){
                        flag = false;
                        break;
                    }
                }
            }
            if(flag){
                board[x][y] = i;
                dfs(L + 1);
                board[x][y] = 0;
            }
        }
    }
}



int main() {
	fastio;
    for(int i{0}; i < 9; ++i){
        for(int j{0}; j < 9; ++j){
            char c;
            cin >> c;
            board[i][j] = c - '0';
            if(board[i][j] == 0) vec.push_back({i, j});
        }
    }
    dfs(0);
}
	

