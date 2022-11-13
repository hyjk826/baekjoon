// 2022-11-13
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
    int m, n;
    cin >> m >> n;
    vl dp(15001);
    map<ll, vp> mp;
    vl A(m);
    for(int i{0}; i < m; ++i){
        cin >> A[i];
    }
    for(int i{0}; i < n; ++i){
        ll a, b, c;
        cin >> a >> b >> c;
        mp[a].push_back({b, A[c - 1] * (b - a)});
    }
    for(int i{1}; i <= 15000; ++i){
        dp[i] = max(dp[i], dp[i - 1]);
        if(!mp.count(i)) continue;
        for(auto& j : mp[i]){
            dp[j.first] = max(dp[j.first], dp[i] + j.second);
        }
    }
    cout << *max_element(dp.begin(), dp.end());
}
	

