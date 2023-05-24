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

int main(){
	fastio;
	int n, m, h, w;
    cin >> n >> m >> h >> w;
    int mn{MAX}, mx{0};
    vector<vi> board(n + 1, vi(m + 1));
    for(int i{1}; i <= n; ++i){
        for(int j{1}; j <= m; ++j){
            cin >> board[i][j];
            mn = min(mn, board[i][j]);
            mx = max(mx, board[i][j]);
        }
    }
    ll l{mn}, r{mx};
    ll ans{-1};
    while(l <= r){
        ll mid{(l + r) >> 1};
        vector<vi> tmp(n + 1, vi(m + 1));
        for(int i{1}; i <= n; ++i){
            for(int j{1}; j <= m; ++j){
                if(board[i][j] < mid) tmp[i][j] = -1;
                else tmp[i][j] = 1;
            }
        }
        for(int i{1}; i <= n; ++i){
            for(int j{1}; j <= m; ++j){
                tmp[i][j] += tmp[i][j - 1] + tmp[i - 1][j] - tmp[i - 1][j - 1];
            }
        }
        bool ok = true;
        for(int i{0}; i <= n - h; ++i){
            for(int j{0}; j <= n - w; ++j){
                int sum = tmp[i + h][j + w] - tmp[i][j + w] - tmp[i + h][j] + tmp[i][j];
                ok &= (sum >= 0);
                if(!ok) break;
            }
            if(!ok) break;
        }
        if(ok){
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    cout << ans;
}