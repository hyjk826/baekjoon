// 2022-08-23
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
    int xx[]{0, 1, 0, -1};
    int yy[]{1, 0, -1, 0};
    int x = 0;
    int y = -1;
    int n, m;
    cin >> n >> m;
    vector<vi> ch(n, vi(m));
    int dir{0};
    int ans{0};
    int cnt{0};
    while(1){
        x += xx[dir];
        y += yy[dir];
        if(x < 0 || x > n -1 || y < 0 || y > m - 1 || ch[x][y] == 1){
            x -= xx[dir];
            y -= yy[dir];
            dir = (dir + 1) % 4;
            ans++;
        }
        else{
            ch[x][y] = 1;
            cnt++;
        }
        if(cnt == n * m) break;
    }
    cout << ans;
}

