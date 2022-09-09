// 2022-09-10
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define vs vector<string>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int main(){
    fastio;
    int n;
    cin >> n;
    vi vec(n);
    for(int i{0}; i < n; ++i) cin >> vec[i];
    vi dp(n);
    dp[0] = vec[0];
    dp[1] = vec[0] + vec[1];
    dp[2] = max(vec[0] + vec[2], vec[1] + vec[2]);
    for(int i{3}; i < n; ++i){
        dp[i] = vec[i] + max(dp[i - 3] + vec[i - 1], dp[i - 2]);
    }
    cout << dp.back();
}