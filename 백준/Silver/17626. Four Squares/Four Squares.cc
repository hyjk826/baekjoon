// 2022-09-11
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

int main() {
    fastio;
    vi dp(50001, MAX);
    vi vec;
    for (int i{ 1 };; ++i) {
        int k = i * i;
        if (k > 50000) break;
        vec.push_back(k);
    }
    dp[0] = 0;
    for (int i{ 1 }; i <= 50000; ++i) {
        for (int j{ 0 }; j < (int)vec.size(); ++j) {
            if (vec[j] > i) break;
            dp[i] = min(dp[i], dp[i - vec[j]] + 1);
        }
    }
    int n;
    cin >> n;
    cout << dp[n];
}