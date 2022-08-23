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

bool f(ll n){
    ll a = (ll)sqrt(n);
    return a * a == n;
}

int main() {
	fastio;
    int n, m;
    cin >> n >> m;
    vector<vc> board(n, vc(m));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            cin >> board[i][j];
        }
    }
    ll mx{-1};
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            for(int a{-n}; a <= n; ++a){
                for(int b{-m}; b <= m; ++b){
                    string str;
                    str += board[i][j];
                    int x = i;
                    int y = j;
                    if(f(stoll(str))) mx = max(mx, stoll(str));
                    while(1){
                        x += a;
                        y += b;
                        if(x == i && y == j) break;
                        if(x < 0 || x > n - 1 || y < 0 || y > m - 1) break;
                        str += board[x][y];
                        if(f(stoll(str))) mx = max(mx, stoll(str));
                    }
                }
            }
        }
    }
    cout << mx;
}

