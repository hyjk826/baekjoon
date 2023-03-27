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

int dp[5001][10][10][10];

int main(){
	fastio;
    int n;
    cin >> n;
    vi vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    memset(dp, -1, sizeof(dp));
    function<int(int,int,int,int)> f = [&](int a, int b, int c, int d){
        if(a == n) return 0;
        if(dp[a][b][c][d] != -1) return dp[a][b][c][d];
        int& ret = dp[a][b][c][d];
        ret = MAX;
        ret = min(ret, min(abs(vec[a] - b), 10 - abs(vec[a] - b)) + f(a + 1, vec[a], c, d));
        ret = min(ret, min(abs(vec[a] - c), 10 - abs(vec[a] - c)) + f(a + 1, b, vec[a], d));
        ret = min(ret, min(abs(vec[a] - d), 10 - abs(vec[a] - d)) + f(a + 1, b, c, vec[a]));
        return ret;
    };
    cout << f(0, 0, 0, 0);
}
