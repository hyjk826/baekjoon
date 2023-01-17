// 2023-01-17
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
    int n;
    cin >> n;
    vi A(n), B(n);
    for(int i{0}; i < n; ++i){
        cin >> A[i];
    }
    for(int i{0}; i < n; ++i){
        cin >> B[i];
    }
    vector<vi> dp(n, vi(n, -1));
    function<int(int, int)> f = [&](int a, int b){
        if(a == n || b == n) return 0;
        if(dp[a][b] != -1) return dp[a][b];
        dp[a][b] = 0;
        dp[a][b] = max(f(a + 1, b + 1), f(a + 1, b));
        if(A[a] > B[b]) dp[a][b] = max(dp[a][b], f(a, b + 1) + B[b]);
        return dp[a][b];
    };
    cout << f(0, 0);
}