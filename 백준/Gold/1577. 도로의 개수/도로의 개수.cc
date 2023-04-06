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
    int ch[101][101][2];
    for(int i{0}; i < k; ++i){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if(x1 == x2){
            ch[x1][max(y1, y2)][0] = 1;
        }
        else{
            ch[max(x1, x2)][y1][1] = 1;
        }
    }
    ll dp[101][101];
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 1;
    function<ll(int,int)> f = [&](int a, int b){
        if(dp[a][b] != -1) return dp[a][b];
        ll& ret = dp[a][b];
        ret = 0;
        if(ch[a][b][0] == 0 && b - 1 >= 0) ret += f(a, b - 1);
        if(ch[a][b][1] == 0 && a - 1 >= 0) ret += f(a - 1, b);
        return ret;
    };
    cout << f(n, m);
}
