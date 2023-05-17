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
    vi vec(n + 1);
    for(int i{1}; i <= n; ++i){
        cin >> vec[i];
    }
    vector<vl> dp(n + 1, vl(7));
    for(int i{1}; i <= n; ++i){
        for(int j{1}; j <= 6; ++j){
            if(j == 1){
                dp[i][j] = dp[i - 1][j] + vec[i];
            }
            else if(j == 3 || j == 5){
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j] + vec[i]);
            }
            else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    cout << dp[n][6];
}
