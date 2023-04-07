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
        int n;
        cin >> n;
        vi ch(10);
        for(int i{0}; i < n; ++i){
            int a;
            cin >> a;
            ch[a]++;
        }
        int q;
        cin >> q;
        vi Q(q);
        int mx{0};
        for(int i{0}; i < q; ++i){
            cin >> Q[i];
            mx = max(mx, Q[i]);
        }
        vi dp(mx + 1, -1);
        function<int(int)> f = [&](int a){
            if(dp[a] != -1) return dp[a];
            bool ok = true;
            int k = a;
            while(k){
                ok &= (ch[k % 10] == 1);
                k /= 10;
            }
            if(ok) return dp[a] = 0;
            int mn{(int)1e9};
            for(int i{2}; i * i <= a; ++i){
                if(a % i != 0) continue;        
                mn = min(mn, f(i) + f(a / i) + 1);
            }
            return dp[a] = mn;
        };
        for(int i{0}; i < q; ++i){
            int ans = f(Q[i]);
            if(ans == (int)1e9) cout << -1 << "\n";
            else cout << ans << "\n";
        }
    }
}
