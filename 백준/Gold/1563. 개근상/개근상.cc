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

int dp[1000][2][3];

int main(){
	fastio;
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    function<int(int,int,int)> f = [&](int a, int b, int c){
        if(a == n) return 1;
        if(dp[a][b][c] != -1) return dp[a][b][c];
        int& ret = dp[a][b][c];
        ret = 0;
        ret += f(a + 1, b, 0);
        if(b == 0) ret += f(a + 1, 1, 0);
        if(c <= 1) ret += f(a + 1, b, c + 1);
        ret %= 1000000;
        return ret;
    };
    cout << f(0, 0, 0);
}
