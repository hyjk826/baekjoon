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

ll dp[1001][1001][2];

int main(){
	fastio;
    int n, m;
    cin >> n >> m;
    vi A(n + 1);
    vl B(n + 1);
    for(int i{1}; i <= n; ++i){
        cin >> A[i] >> B[i];
        B[i] += B[i - 1];
    }
    memset(dp, -1, sizeof(dp));
    dp[1][n][0] = dp[1][n][1] = 0;
    function<ll(int,int,int)> f = [&](int l, int r, int state){
        if(dp[l][r][state] != -1) return dp[l][r][state];
        ll& ret = dp[l][r][state];
        ret = LLONG_MAX;
        int cur;
        if(state == 0) cur = l;
        else cur = r;
        ll k = B.back() - (B[r] - B[l - 1]);
        if(l != 1){
            ret = min(ret, f(l - 1, r, 0) + (A[cur] - A[l - 1]) * k);
        }   
        if(r != n){
            ret = min(ret, f(l, r + 1, 1) + (A[r + 1] - A[cur]) * k);
        }
        return ret;
    };
    cout << f(m, m, 0);
}
