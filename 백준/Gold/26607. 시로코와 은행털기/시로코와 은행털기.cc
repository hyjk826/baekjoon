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
#define MOD 1000000007
using namespace std;


int main(){
	fastio;
    int n, k, x;
    cin >> n >> k >> x;
    vector<vector<bool> > dp(k + 1, vector<bool>(k * 200 + 1));
    dp[0][0] = 1;
    for(int i{0}; i < n; ++i){
        int a, b;
        cin >> a >> b;
        for(int j{k - 1}; j >= 0; --j){
            for(int z{k * 200}; z >= 0; --z){
                if(dp[j][z] == 0) continue;
                dp[j + 1][a + z] = 1;
            }
        }
    }
    int ans{0};
    for(int i{1}; i <= k * 200; ++i){
        if(dp[k][i] == 0) continue;
        ans = max(ans,  i * (k * x - i));
    }
    cout << ans;
}
