// 2022-08-25
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

int n;
vi vec(3);
vector<vi> board(10, vi(10));
int xx[]{-1,0,1,0};
int yy[]{0,1,0,-1};
int ans{MAX};

void dfs(int L, int k){
    if(L == 3){
        vector<vi> ch(n, vi(n));
        int sum{0};
        for(int i{0}; i < 3; ++i){
            int x = vec[i] / n;
            int y = vec[i] % n;
            sum += board[x][y];
            ch[x][y] = 1;
            for(int dir{0}; dir < 4; ++dir){
                int nx{x + xx[dir]};
                int ny{y + yy[dir]};
                if(nx < 0 || nx > n - 1 || ny < 0 || ny > n - 1 || ch[nx][ny] == 1){
                    sum = MAX;
                    break;
                }
                ch[nx][ny] = 1;
                sum += board[nx][ny];
            }
            if(sum == MAX) break;
        }
        ans = min(ans, sum);
    }
    else{
        for(int i{k + 1}; i < n * n; ++i){
            vec[L] = i;
            dfs(L + 1, i);
        }
    }
}
int main() {
	fastio;
    cin >> n;
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < n; ++j){
            cin >> board[i][j];
        }
    }
    dfs(0, -1);
    cout << ans;
}

