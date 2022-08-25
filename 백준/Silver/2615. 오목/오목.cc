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
    vector<vi> board(19, vi(19));
    for(int i{0}; i < 19; ++i){
        for(int j{0}; j < 19; ++j){
            cin >> board[i][j];
        }
    }
    int xx[]{-1, 0, 1, 1};
    int yy[]{1, 1, 1, 0};
    for(int j{0}; j < 19; ++j){
        for(int i{0}; i < 19; ++i){
            if(board[i][j] == 0) continue;
            for(int dir{0}; dir < 4; ++dir){
                int x = i;
                int y = j;
                int cnt{1};
                while(1){
                    x += xx[dir];
                    y += yy[dir];
                    if(x < 0 || x > 18 || y < 0 || y > 18 || board[x][y] != board[i][j]) break;
                    cnt++;                    
                }
                    if(cnt == 5){
                    int nx = i - xx[dir];
                    int ny = j - yy[dir];
                    if(nx >= 0 && nx <= 18 && ny >= 0 && ny <= 18 && board[nx][ny] == board[i][j]) continue;
                    cout << board[i][j] << "\n";
                    cout << i + 1 << " " << j + 1 << "\n";
                    return 0;
                }
            }
        }
    }
    cout << 0;
}

