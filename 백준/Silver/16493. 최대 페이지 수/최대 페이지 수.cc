// 2022-12-08
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
	int n, m;
    cin >> n >> m;
    vi dp(n + 1, -1);
    dp[0] = 0;
    for(int i{0}; i < m; ++i){
        int a, b;
        cin >> a >> b;
        for(int j{n - a}; j >= 0; --j){
            if(dp[j] == -1) continue;
            dp[j + a] = max(dp[j + a], dp[j] + b);
        }
    }
    cout << *max_element(dp.begin(), dp.end());
}
	
