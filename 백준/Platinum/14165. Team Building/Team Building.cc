// 2023-01-03
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
#define MOD 1000000009
using namespace std;

ll dp[11][1001][1001];
ll sum[11][1001][1001];

int main(){
	fastio;
    int n, m, k;
    cin >> n >> m >> k;
    vi A(n + 1), B(m + 1);
    for(int i{1}; i <= n; ++i){
        cin >> A[i];
    }
    for(int i{1}; i <= m; ++i){
        cin >> B[i];
    }
    sort(A.begin() + 1, A.end());
    sort(B.begin() + 1, B.end());
    for(int i{1}; i <= k; ++i){
        for(int j{1}; j <= n; ++j){
            for(int a{1}; a <= m; ++a){
                if(A[j] > B[a]){
                    if(i == 1) dp[i][j][a] = 1;
                    else dp[i][j][a] = sum[i - 1][j - 1][a - 1];
                }
            }
        }
        for(int j{1}; j <= n; ++j){
            for(int a{1}; a <= m; ++a){
                sum[i][j][a] = (sum[i][j - 1][a] + sum[i][j][a - 1] - sum[i][j - 1][a - 1] + MOD + dp[i][j][a]) % MOD; 
            }
        }
    }
    cout << sum[k][n][m];
}
