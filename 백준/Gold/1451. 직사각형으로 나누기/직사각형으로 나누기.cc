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
    int n, m;
    cin >> n >> m;
    vector<vi> board(n + 1, vi(m + 1));
    for(int i{1}; i <= n; ++i){
        for(int j{1}; j <= m; ++j){
            char c;
            cin >> c;
            board[i][j] = c - '0';
        }
    }
    for(int i{1}; i <= n; ++i){
        for(int j{1}; j <= m; ++j){
            board[i][j] += board[i][j - 1];
        }
    }
    for(int j{1}; j <= m; ++j){
        for(int i{1}; i <= n; ++i){
            board[i][j] += board[i - 1][j];
        }
    }
    function<int(int,int,int,int)> f = [&](int x1, int y1, int x2, int y2){
        int ret{0};
        ret += board[x2][y2];
        ret -= board[x1 - 1][y2];
        ret -= board[x2][y1 - 1];
        ret += board[x1 - 1][y1 - 1];
        return ret;
    };
    ll ans{0};
    for(int i{2}; i < m; ++i){
        for(int j{i}; j < m; ++j){
            ans = max(ans, 1LL * f(1, 1, n, i - 1) * f(1, i, n, j) * f(1, j + 1, n, m));
        }
    }
    for(int i{2}; i < n; ++i){
        for(int j{i}; j < n; ++j){
            ans = max(ans, 1LL * f(1, 1, i - 1, m) * f(i, 1, j, m) * f(j + 1, 1, n, m));
        }
    }
    for(int i{1}; i < n; ++i){
        for(int j{1}; j < m; ++j){
            ans = max(ans, 1LL * f(1, 1, i, j) * f(1, j + 1, i, m) * f(i + 1, 1, n, m));
            ans = max(ans, 1LL * f(1, 1, i, m) * f(i + 1, 1, n, j) * f(i + 1, j + 1, n, m));
        }
    }
    for(int i{1}; i < m; ++i){
        for(int j{1}; j < n; ++j){
            ans = max(ans, 1LL * f(1, 1, j, i) * f(j + 1, 1, n, i) * f(1, i + 1, n, m));
            ans = max(ans, 1LL * f(1, 1, n, i) * f(1, i + 1, j, m) * f(j + 1, i + 1, n, m));
        }
    }
    cout << ans;
}
