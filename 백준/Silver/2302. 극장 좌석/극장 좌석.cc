// 2022-07-27
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
    int n, m;
    cin >> n >> m;
    vi vec;
    vec.push_back(0);
    for(int i{0}; i < m; ++i){
        int a;
        cin >> a;
        vec.push_back(a);
    }
    vec.push_back(n + 1);
    vi v;
    for(int i{1}; i < (int)vec.size(); ++i){
        v.push_back(vec[i] - vec[i - 1] - 1);
    }
    vi dp(41);
    dp[0] = dp[1] = 1;
    for(int i{2}; i <= 40; ++i){
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    int ans{1};
    for(int i{0}; i < (int)v.size(); ++i){
        ans *= dp[v[i]];
    }
    cout << ans;
}

