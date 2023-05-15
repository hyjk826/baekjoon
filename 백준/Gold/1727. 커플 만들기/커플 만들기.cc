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
    int n, m;
    cin >> n >> m;
    vi A(n), B(m);
    for(int i{0}; i < n; ++i) cin >> A[i];
    for(int i{0}; i < m; ++i) cin >> B[i];
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    vector<vi> dp(n, vi(m, -1));
    function<int(int,int)> f = [&](int a, int b){
        if(a == n || b == m) return 0;
        if(dp[a][b] != -1) return dp[a][b];
        dp[a][b] = MAX;
        if(n - a == m - b){
            dp[a][b] = abs(A[a] - B[b]) + f(a + 1, b + 1);
        }
        else if(n - a > m - b){
            dp[a][b] = abs(A[a] - B[b]) + f(a + 1, b + 1);
            dp[a][b] = min(dp[a][b], f(a + 1, b));
        }
        else{
            dp[a][b] = abs(A[a] - B[b]) + f(a + 1, b + 1);
            dp[a][b] = min(dp[a][b], f(a, b + 1));
        }
        return dp[a][b];
    };
    cout << f(0, 0);
}
