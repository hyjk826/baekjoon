// 2022-08-18
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
#define MAX 1000000000
#define MOD 1000000007
using namespace std;

int main() {
	fastio;
    int n;
    cin >> n;
    vector<vi> board(n, vi(n));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < n; ++j){
            cin >> board[i][j];
        }
    }
    vector<vi> dp1(n, vi(n, MAX));
    int xx[]{-1, 0};
    int yy[]{0, -1};
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < n; ++j){
            if(board[i][j] == 0) continue;
            dp1[i][j] = 0;
            int a = board[i][j];            
            while(a % 2 == 0){
                a /= 2;
                dp1[i][j]++;
            }
            if(i == 0 && j == 0) continue;
            int mn{MAX};
            for(int dir{0}; dir < 2; ++dir){
                int nx{i + xx[dir]};
                int ny{j + yy[dir]};
                if(nx < 0 || nx > n - 1 || ny < 0 || ny > n - 1 || board[nx][ny] == 0) continue;
                mn = min(mn, dp1[nx][ny]);
            }
            if(mn == MAX) dp1[i][j] = MAX;
            else dp1[i][j] += mn;
        }
    }
    vector<vi> dp2(n, vi(n, MAX));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < n; ++j){
            if(board[i][j] == 0) continue;
            dp2[i][j] = 0;
            int a = board[i][j];            
            while(a % 5 == 0){
                a /= 5;
                dp2[i][j]++;
            }
            if(i == 0 && j == 0) continue;
            int mn{MAX};
            for(int dir{0}; dir < 2; ++dir){
                int nx{i + xx[dir]};
                int ny{j + yy[dir]};
                if(nx < 0 || nx > n - 1 || ny < 0 || ny > n - 1 || board[nx][ny] == 0) continue;
                mn = min(mn, dp2[nx][ny]);
            }
            if(mn == MAX) dp2[i][j] = MAX;
            else dp2[i][j] += mn;
        }
    }
    cout << min(dp1[n - 1][n - 1], dp2[n - 1][n - 1]);
}