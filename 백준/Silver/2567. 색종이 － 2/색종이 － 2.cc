// 2022-08-19
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
    vector<vi> board(102, vi(102, 1));
    for(int i{0}; i < n; ++i){
        int a, b;
        cin >> a >> b;
        for(int j{a}; j < a + 10; ++j){
            for(int k{b}; k < b + 10; ++k){
                board[j][k] = 0;
            }
        }
    }
    int ans{0};
    int xx[]{-1,0,1,0};
    int yy[]{0,1,0,-1};
    for(int i{1}; i <= 100; ++i){
        for(int j{1}; j <= 100; ++j){
            if(board[i][j] == 0){
                for(int dir{0}; dir < 4; ++dir){
                    int nx{i + xx[dir]};
                    int ny{j + yy[dir]};
                    ans += board[nx][ny];
                }
            }
        }
    }
    cout << ans;
}