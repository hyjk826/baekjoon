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

int n;
vector<double> vec(4);
vector<vi> ch(31, vi(31));
double ans{0};
int xx[]{0, 0, -1, 1};
int yy[]{1,-1, 0, 0};

void dfs(int L, int x, int y, double p){
    if(L >= n) return;
    for(int dir{0}; dir < 4; ++dir){
        int nx{x + xx[dir]};
        int ny{y + yy[dir]};
        if(ch[nx][ny] == 1 && L < n){
            ans += p * vec[dir];
        }
        else{
            ch[nx][ny] = 1;
            dfs(L + 1, nx, ny, p * vec[dir]);
            ch[nx][ny] = 0;
        }
    }
}

int main() {
	fastio;
    cin >> n;
    for(int i{0}; i < 4; ++i){
        cin >> vec[i];
        vec[i] /= 100;
    }
    cout << fixed << setprecision(10);
    ch[15][15] = 1;
    dfs(0, 15, 15, 1);
    cout << 1 - ans;
}

