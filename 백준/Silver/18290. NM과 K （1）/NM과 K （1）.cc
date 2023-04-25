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
    int n, m, k;
    cin >> n >> m >> k;
    vector<vi> board(n, vi(m));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            cin >> board[i][j];
        }
    }
    vp A;
    int ans{-MAX};
    vector<vi> ch(n, vi(m));
    int xx[]{-1,0,1,0};
    int yy[]{0,1,0,-1};
    function<void(int,int)> f = [&](int L, int sum){
        if(L == k){
            ans = max(ans, sum);
        }
        else{
            for(int i{0}; i < n; ++i){
                for(int j{0}; j < m; ++j){
                    if(ch[i][j]) continue;
                    bool ok = true;
                    for(int dir{0}; dir < 4; ++dir){
                        int nx{i + xx[dir]};
                        int ny{j + yy[dir]};
                        if(nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1) continue;
                        if(ch[nx][ny]) ok = false;
                    }
                    if(ok) {
                        ch[i][j] = 1;
                        f(L + 1, sum + board[i][j]);
                        ch[i][j] = 0;
                    }
                }
            }
        }
    };
    f(0, 0);
    cout << ans;
}
