// 2022-09-25
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
    int n;
    cin >> n;
    int x, y;
    cin >> x >> y;
    vp vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i].first >> vec[i].second;
    }
    vector<vl> dp(n, vl(4, (ll)1e18));
    int xx[]{-1,0,1,0};
    int yy[]{0,1,0,-1};
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < 4; ++j){
            int nx{vec[i].first + xx[j]};
            int ny{vec[i].second + yy[j]};
            if(i == 0){
                dp[i][j] = abs(x - nx) + abs(y - ny);
            }
            else{
                for(int k{0}; k < 4; ++k){
                    int a = vec[i - 1].first + xx[k];
                    int b = vec[i - 1].second + yy[k];
                    dp[i][j] = min(dp[i][j], dp[i - 1][k] + abs(nx - a) + abs(ny - b));
                }
            }
        }
    }
    ll ans{LLONG_MAX};
    for(int i{0}; i < 4; ++i){
        ans = min(ans, dp[n - 1][i]);
    }
    cout << ans;
}
	

