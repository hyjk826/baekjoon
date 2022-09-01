// 2022-09-01
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
    int xx[]{-1,0,1,0};
    int yy[]{0,1,0,-1};
    vector<vi> board(10, vi(10));
    for(int i{0}; i < 10; ++i){
        for(int j{0}; j < 10; ++j){
            char c;
            cin >> c;
            if(c == 'O') board[i][j] = 1;
        }
    }
    int ans{MAX};
    for(int i{0}; i < (1 << 10); ++i){
        vector<vi> copy = board;
        int cnt{0};
        for(int j{0}; j < 10; ++j){
            if((i >> j) & 1){
                cnt++;
                for(int dir{0}; dir < 4; ++dir){
                    int nx{0 + xx[dir]};
                    int ny{j + yy[dir]};
                    if(nx < 0 || nx > 9 || ny < 0 || ny > 9) continue;
                    copy[nx][ny] ^= 1;
                }
                copy[0][j] ^= 1;
            }
        }
        for(int j{1}; j < 10; ++j){
            for(int k{0}; k < 10; ++k){
                if(copy[j - 1][k] == 1){
                    cnt++;
                    for(int dir{0}; dir < 4; ++dir){
                        int nx{j + xx[dir]};
                        int ny{k + yy[dir]};
                        if(nx < 0 || nx > 9 || ny < 0 || ny > 9) continue;
                        copy[nx][ny] ^= 1;
                    }
                    copy[j][k] ^= 1;
                }
            }
        }
        int sum{0};
        for(int j{0}; j < 10; ++j){
            sum += copy[9][j];
        }
        if(sum == 0){
            ans = min(ans, cnt);
        }
    }
    if(ans == MAX) cout << -1;
    else cout << ans;
}

