// 2022-07-25
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

int ch[1001][1001];

int main() {
	fastio;
    int n;
    cin >> n;
    memset(ch, -1, sizeof(ch));
    ch[1][0] = 0;
    queue<pi> Q;
    Q.push({1, 0});
    int ans{MAX};
    while(!Q.empty()){
        int x{Q.front().first};
        int c{Q.front().second};
        Q.pop();
        if(x == n) ans = min(ans, ch[x][c]);
        if(ch[x][x] == -1){
            ch[x][x] = ch[x][c] + 1;
            Q.push({x, x});
        }
        if(x + c <= 1000 && ch[x + c][c] == -1){
            ch[x + c][c] = ch[x][c] + 1;
            Q.push({x + c, c});
        }
        if(x > 0 && ch[x - 1][c] == -1){
            ch[x - 1][c] = ch[x][c] + 1;
            Q.push({x - 1, c});
        }
    }
    cout << ans;
}

