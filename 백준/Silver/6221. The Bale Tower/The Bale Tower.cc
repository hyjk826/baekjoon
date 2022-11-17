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
    int n;
    cin >> n;
    vp vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i].first >> vec[i].second;
    }
    sort(vec.begin(), vec.end());
    vi A;
    A.push_back(-1);
    for(auto& i : vec){
        A.push_back(i.second);
    }
    vi dp(n + 1);
    int ans{0};
    for(int i{1}; i <= n; ++i){
        int mx{0};
        for(int j{0}; j < i; ++j){
            if(A[i] > A[j]){
                mx = max(mx, dp[j]);
            }
        }
        dp[i] = mx + 1;
        ans = max(ans, dp[i]);
    }
    cout << ans;
}
	

