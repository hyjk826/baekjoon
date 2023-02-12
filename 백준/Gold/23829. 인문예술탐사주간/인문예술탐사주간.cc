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
    int n, q;
    cin >> n >> q;
    vl vec(n + 1);
    for(int i{1}; i <= n; ++i){
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    vl pre = vec;
    for(int i{1}; i <= n; ++i){
        pre[i] += pre[i - 1];
    }
    while(q--){
        ll a;
        cin >> a;
        int idx = lower_bound(vec.begin(), vec.end(), a) - vec.begin();
        ll ans{0};
        ans += (pre.back() - pre[idx - 1]) - a * (n - idx + 1);
        ans += a * (idx - 1) - pre[idx - 1];
        cout << ans << "\n"; 
    }
}
