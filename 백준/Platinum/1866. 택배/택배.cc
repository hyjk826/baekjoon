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

void solve(){
	int n;
    cin >> n;
    vi vec(n + 1);
    for(int i{1}; i <= n; ++i) cin >> vec[i];
    sort(vec.begin() + 1, vec.end());
    auto pre = vec;
    for(int i{1}; i <= n; ++i) pre[i] += pre[i - 1];
    vi dp(n + 1);
    int a, b;
    cin >> a >> b;
    for(int i{1}; i <= n; ++i){
        dp[i] = dp[i - 1] + vec[i] * a;
        for(int j{i}; j >= 1; --j){
            int sum{b};
            int idx = (i + j) / 2;
            int r = pre[i] - pre[idx - 1];
            int rcnt = i - idx + 1;
            int l = pre[idx - 1] - pre[j - 1];
            int lcnt = idx - j;
            sum += (r - rcnt * vec[idx]) * a;
            sum += (lcnt * vec[idx] - l) * a;
            dp[i] = min(dp[i], dp[j - 1] + sum);
        }
    }
    cout << dp[n] << "\n";
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
