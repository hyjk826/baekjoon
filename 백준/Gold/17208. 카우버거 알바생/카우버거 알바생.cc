// 2022-12-14
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
    int n, m, k;
    cin >> n >> m >> k;
    vector<vi> board(m + 1, vi(k + 1, -1));
    board[0][0] = 0;
    int ans{0};
    for(int i{0}; i < n; ++i){
        int a, b;
        cin >> a >> b;
        for(int j{m - a}; j >= 0; --j){
            for(int x{k - b}; x >= 0; --x){
                if(board[j][x] == -1) continue;
                board[j + a][x + b] = max(board[j + a][x + b], board[j][x] + 1);
                ans = max(ans, board[j + a][x + b]);
            }
        }
    }
    cout << ans;
}
	
