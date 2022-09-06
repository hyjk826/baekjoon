// 2022-09-06
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
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int main() {
	fastio;
    int b, n;
    cin >> b >> n;
    vl vec(n + 1);
    for(int i{1}; i <= n; ++i){
        cin >> vec[i];
    }
    vl A(n + 1);
    A = vec;
    for(int i{1}; i <= n; ++i){
        A[i] += A[i - 1];
    }
    vl B = vec;
    for(int i{1}; i <= n; ++i){
        B[i] *= B[i];
        B[i] += B[i - 1];
    }
    if(b >= n){
        cout << 0;
        return 0;
    }
    cout << fixed << setprecision(15);
    vector<vector<double> > dp(n + 1, vector<double>(b + 1, (double)(ll)1e18));
    dp[0][0] = 0.0;
    for(int i{1}; i <= n; ++i){
        for(int j{1}; j <= min(i, b); ++j){
            for(int k{j - 1}; k <= i - 1; ++k){
                double d = B[i] - B[k] - 1.0 * (A[i] - A[k]) * (A[i] - A[k]) / (i - k);
                dp[i][j] = min(dp[i][j], dp[k][j - 1] + d);
            }   
        }
    }
    cout << dp[n][b];
}
	

