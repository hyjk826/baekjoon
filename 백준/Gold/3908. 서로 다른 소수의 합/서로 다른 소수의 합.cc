// 2022-11-20
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

int main() {
	fastio;	
	int t;
    cin >> t;    
    vi prime(1121);
    for(int i{2}; i <= 1120; ++i){
        if(prime[i] == 0){
            for(int j{i * 2}; j <= 1120; j += i){
                prime[j] = 1;
            }
        }
    }
    vi A;
    for(int i{2}; i <= 1120; ++i){
        if(prime[i] == 0) A.push_back(i);
    }
    vector<vector<vi> > dp((int)A.size() + 1, vector<vi>(1121, vi(15)));
    dp[0][0][0] = 1;
    for(int i{0}; i < (int)A.size(); ++i){
        dp[i + 1] = dp[i];
        for(int j{0}; j + A[i] <= 1120; ++j){
            for(int a{0}; a < 14; ++a){
                dp[i + 1][j + A[i]][a + 1] += dp[i][j][a];
            }
        }
    } 
    while(t--){
        int n, k;
        cin >> n >> k;
        cout << dp[(int)A.size()][n][k] << "\n";
    }	
}   
	

