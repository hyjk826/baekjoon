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

int dp[50][51][51][51];

int main(){
	fastio;
    int N, A, B, C;
    cin >> N >> A >> B >> C;
    memset(dp, -1, sizeof(dp));
    function<int(int,int,int,int)> f = [&](int n, int a, int b, int c){
        if(a < 0 || b < 0 || c < 0) return 0;
        if(n == N) {
            if(a == 0 && b == 0 && c == 0) return 1;
            else return 0;
        }
        if(dp[n][a][b][c] != -1) return dp[n][a][b][c];
        int& ret = dp[n][a][b][c];
        ret = 0;
        ret += f(n + 1, a - 1, b, c); ret %= MOD;
        ret += f(n + 1, a, b - 1, c); ret %= MOD;
        ret += f(n + 1, a, b, c - 1); ret %= MOD;
        ret += f(n + 1, a - 1, b - 1, c); ret %= MOD;
        ret += f(n + 1, a - 1, b, c - 1); ret %= MOD;
        ret += f(n + 1, a, b - 1, c - 1); ret %= MOD;
        ret += f(n + 1, a - 1, b - 1, c - 1); ret %= MOD;
        return ret;
    };
    cout << f(0, A, B, C);
}
