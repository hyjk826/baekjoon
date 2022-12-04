// 2022-12-04
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


int main() {
	fastio;
	int n;
    cin >> n;
    int sx, sy, tx, ty;
    vector<vi> board(n, vi(n));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < n; ++j){
            cin >> board[i][j];
            if(board[i][j] == 2){
                sx = i; sy = j;
            }
            else if(board[i][j] == 5){
                tx = i; ty = j;
            }
        }
    }
    int cnt{0};
    for(int i{min(sx, tx)}; i <= max(sx, tx); ++i){
        for(int j{min(sy, ty)}; j <= max(sy, ty); ++j){
            if(board[i][j] == 1) cnt++;
        }
    }
    int a = sx - tx;
    int b = sy - ty;
    if(cnt >= 3 && a * a + b * b >= 25) cout << 1;
    else cout << 0;
}
	
