// 2022-07-28
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

int n, m;
int ans{0};
int xx[]{-1,0,1};
int yy[]{1,1,1};
bool flag = false;
vector<vi> ch;
void dfs(int x, int y){
    if(flag) return;
    if(y == m - 1){
        ans++;
        flag = true;
    }
    else{
        for(int dir{0}; dir < 3; ++dir){
            int nx = x + xx[dir];
            int ny = y + yy[dir];
            if(nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1) continue;
            if(ch[nx][ny] == 0){
                ch[nx][ny] = 1;
                dfs(nx, ny);
                if(flag) return;
            }
        }
    }
}

int main() {
	fastio;
    cin >> n >> m;
    ch.resize(n, vi(m));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            char c;
            cin >> c;
            if(c == 'x') ch[i][j] = 1;
        }
    }
    for(int i{0}; i < n; ++i){
        flag = false;
        ch[i][0] = 1;
        dfs(i, 0);
    }
    cout << ans;
}

