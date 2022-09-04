// 2022-09-05
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
    vector<vi> board(2, vi(2));
    for(int i{0}; i < 2; ++i){
        for(int j{0}; j < 2; ++j){
            cin >> board[i][j];
        }
    }
    double mx{0};
    int ans{0};
    mx = 1.0 * board[0][0] / board[1][0] + 1.0 * board[0][1] / board[1][1];
    for(int i{0}; i < 4; ++i){
        int a = board[0][0];
        board[0][0] = board[1][0];
        board[1][0] = board[1][1];
        board[1][1] = board[0][1];
        board[0][1] = a;
        double k = 1.0 * board[0][0] / board[1][0] + 1.0 * board[0][1] / board[1][1];
        if(mx < k){
            mx = k;
            ans = i + 1;
        }
    }
    cout << ans;
}
	

