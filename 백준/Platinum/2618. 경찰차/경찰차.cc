// 2022-07-12
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

vector<vi> dp(1001, vi(1001, -1));
vector<vi> ch(1001, vi(1001, -1));
int n, m;
vp vec;

int Dp(int a, int b){
    if(a == m || b == m) return dp[a][b] = 0;
    if(dp[a][b] != -1) return dp[a][b];
    int nx = max(a, b) + 1;
    int x, y;
    if(a == 0){
        x = Dp(nx, b) + abs(1 - vec[nx].first) + abs(1 - vec[nx].second);
    }
    else x = Dp(nx, b) + abs(vec[a].first - vec[nx].first) + abs(vec[a].second - vec[nx].second);
    if(b == 0){
        y = Dp(a, nx) + abs(vec[nx].first - n) + abs(vec[nx].second - n);
    }
    else y = Dp(a, nx) + abs(vec[b].first - vec[nx].first) + abs(vec[b].second - vec[nx].second);
    if(x < y){
        ch[a][b] = 1;
    }
    else ch[a][b] = 2;
    return dp[a][b] = min(x, y);
}

int main() {
	fastio;
    cin >> n >> m;
    vec.resize(m + 1);
    for(int i{1}; i <= m; ++i){
        cin >> vec[i].first >> vec[i].second;
    }
    cout << Dp(0, 0) << "\n";
    int a = 0;
    int b = 0;
    while(1){
        if(ch[a][b] == -1) break;
        cout << ch[a][b] << "\n";
        int nx = max(a, b) + 1;
        if(ch[a][b] == 1){
            a = nx;
        }
        else b = nx;
    }
}
