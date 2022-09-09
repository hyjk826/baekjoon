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
    ll n, m, k;
    cin >> n >> m >> k;
    ll time{MAX}, ans{0};
    vector<vl> board(n, vl(m));
    ll mn{MAX}, mx{0};
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            cin >> board[i][j];
            mn = min(mn, board[i][j]);
            mx = max(mx, board[i][j]);
        }
    }
    for(int i{mn}; i <= mx; ++i){
        ll sum{0};
        ll cnt = k;
        for(int j{0}; j < n; ++j){
            for(int k{0}; k < m; ++k){
                if(board[j][k] >= i){
                    sum += 2 * (board[j][k] - i);
                    cnt += board[j][k] - i;
                }
                else{
                    sum += i - board[j][k];
                    cnt -= i - board[j][k];
                }
            }
        }
        if(sum <= time && cnt >= 0){
            time = sum;
            ans = i;
        }
    }
    cout << time << " " << ans;
}