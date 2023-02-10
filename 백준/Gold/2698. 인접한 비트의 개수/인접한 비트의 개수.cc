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
    int dp[101][101][2];
    for(int i{0}; i <= 100; ++i){
        for(int j{0}; j <= 100; ++j){
            for(int k{0}; k < 2; ++k){
                dp[i][j][k] = -1;
            }
        }
    }
    dp[1][0][0] = dp[1][0][1] = 1;
    function<int(int,int,int)> f = [&](int a, int b, int c){
        if(dp[a][b][c] != -1) return dp[a][b][c];
        if(a == 1 || b < 0) return dp[a][b][c] = 0;
        dp[a][b][c] = 0;
        if(c == 0) dp[a][b][c] += f(a - 1, b, 1) + f(a - 1, b, 0);
        else{
            dp[a][b][c] += f(a - 1, b, 0);
            dp[a][b][c] += f(a - 1, b - 1, 1);
        }
        return dp[a][b][c];
    };
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        cout << f(n, k, 0) + f(n, k, 1) << "\n";
    }
}
