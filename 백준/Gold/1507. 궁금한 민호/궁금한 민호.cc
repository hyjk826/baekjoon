// 2022-11-14
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
    vector<vi> board(n, vi(n));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < n; ++j){
            cin >> board[i][j];
        }
    }
    int ans{0};
    for(int i{0}; i < n; ++i){
        for(int j{i + 1}; j < n; ++j){
            bool flag = false;
            for(int k{0}; k < n; ++k){
                if(k == i || k == j) continue;
                if(board[i][k] + board[k][j] < board[i][j]){
                    cout << -1;
                    return 0;
                }
                else if(board[i][k] + board[k][j] == board[i][j]){
                    flag = true;
                }
            }
            if(!flag) ans += board[i][j];
        }
    }
    cout << ans;
}
	

