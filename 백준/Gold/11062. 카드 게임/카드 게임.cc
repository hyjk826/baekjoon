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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vi vec(n + 1);
        for(int i{1}; i <= n; ++i){
            cin >> vec[i];
        }
        vi pre(n + 1);
        for(int i{1}; i <= n; ++i){
            pre[i] = vec[i] + pre[i - 1];
        }
        vector<vi> dp(n + 1, vi(n + 1, -1));
        function<int(int,int)> f = [&](int a, int b){
            if(a > b) return 0;
            if(dp[a][b] != -1) return dp[a][b];
            if(a == b) return dp[a][b] = vec[a];
            dp[a][b] = 0;
            dp[a][b] = max(dp[a][b], pre[b - 1] - pre[a - 1] - f(a, b - 1) + vec[b]);
            dp[a][b] = max(dp[a][b], pre[b] - pre[a] - f(a + 1, b) + vec[a]);
            return dp[a][b];
        };
        cout << f(1, n) << "\n";
    }
}