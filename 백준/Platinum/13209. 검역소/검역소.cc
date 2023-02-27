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

int main(){
	fastio;
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vi X(n + 1);
        for(int i{1}; i <= n; ++i){
            cin >> X[i];
        }
        vector<vi> g(n + 1);
        for(int i{0}; i < n - 1; ++i){
            int a, b;
            cin >> a >> b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        ll l{1}, r{(ll)1e14};
        ll ans{-1};
        while(l <= r){
            ll mid{(l + r) >> 1};
            int cnt{0};
            vl dp(n + 1);
            function<void(int,int)> f = [&](int cur, int pre){
                if(cnt == MAX) return;
                dp[cur] = X[cur];
                if(dp[cur] > mid) {
                    cnt = MAX;
                    return;
                }
                vl A;
                for(auto& i : g[cur]){
                    if(i == pre) continue;
                    f(i, cur);
                    A.push_back(dp[i]);
                    dp[cur] += dp[i];
                }
                
                sort(A.rbegin(), A.rend());
                for(int i{0}; i < (int)A.size(); ++i){
                    if(dp[cur] <= mid) break;
                    cnt++;
                    dp[cur] -= A[i];
                }
            };
            f(1, -1);
            if(cnt <= k){
                r = mid - 1;
                ans = mid;
            }
            else l = mid + 1;
        }
        cout << ans << "\n";
    }
}
