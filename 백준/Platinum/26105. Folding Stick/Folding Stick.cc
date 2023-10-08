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

bool comp(const pi &a, const pi &b){
    if(a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

void solve(){
    int n;
    cin >> n;
    vl vec(n + 1);
    for(int i{1}; i <= n; ++i) cin >> vec[i];
    vl pre = vec;
    for(int i{1}; i <= n; ++i){
        pre[i] += pre[i - 1];
    }
    vl A, B;
    A.push_back(0);
    B.push_back(0);
    vl dp = pre;
    for(int i{1}; i <= n; ++i){        
        int idx = upper_bound(A.begin(), A.end(), dp[i]) - A.begin() - 1;
        dp[i] = pre[i] - B[idx];
        while(!A.empty() && A.back() >= dp[i] + pre[i]) {
            A.pop_back(); B.pop_back();
        }
        A.push_back(dp[i] + pre[i]);
        B.push_back(pre[i]);
    }
    ll ans{LLONG_MAX};
    for(int i{0}; i <= n; ++i){
        ans = min(ans, max(dp[i], pre[n] - pre[i]));
    }
    cout << ans << "\n";
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
