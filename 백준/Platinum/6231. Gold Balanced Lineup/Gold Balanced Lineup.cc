// 2022-11-16
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
    int n, k;
    cin >> n >> k;
    vi vec(n + 1);
    for(int i{1}; i <= n; ++i) cin >> vec[i];
    vector<vi> dp(n + 1, vi(k));
    for(int i{0}; i <= n; ++i){
        int c = vec[i];
        int cnt{0};
        while(c){
            if(c % 2) dp[i][cnt]++;
            c /= 2;
            cnt++;
        }
        for(int j{0}; j < k; ++j){
            if(i){
                dp[i][j] += dp[i - 1][j];
            }
        }
    }
    int ans{0};
    map<string, int> mp;
    for(int i{0}; i <= n; ++i){
        string str;
        for(int j{0}; j < k - 1; ++j){
            str += char('0' + (dp[i][j + 1] - dp[i][j]));
        }
        if(mp.count(str)){
            ans = max(ans, i - mp[str]);
        }
        else mp[str] = i;
    }
    cout << ans;
}
	

