// 2022-12-12
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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vi vec(n + 1);
        for(int i{1}; i <= n; ++i){
            cin >> vec[i];
        }
        sort(vec.begin() + 1, vec.end());
        vl pre(n + 1);
        for(int i{1}; i <= n; ++i){
            pre[i] = vec[i] + pre[i - 1];
        }
        ll ans{0};
        for(int i{1}; i <= n; ++i){
            ll mn{LLONG_MAX};
            for(int j{0}; j + i <= n; ++j){
                mn = min(mn, 1LL * vec[j + i] * i - (pre[j + i] - pre[j]));
            }
            ans += mn;
        }
        cout << ans << "\n";
    }
}
	
