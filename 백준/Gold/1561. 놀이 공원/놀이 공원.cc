// 2022-09-27
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
    ll n, k;
    cin >> n >> k;
    if(n <= k){
        cout << n;
        return 0;
    }
    vi vec(k);
    for(int i{0}; i < k; ++i){
        cin >> vec[i];
    }
    ll l{0}, r{LLONG_MAX / 10000};
    ll mx{0};
    while(l <= r){
        ll m{(l + r) / 2};
        ll cnt{0};
        for(int i{0}; i < k; ++i){
            cnt += m / vec[i] + 1;
        }
        if(cnt <= n - 1){
            l = m + 1;
            mx = max(mx, m);
        }
        else r = m - 1;
    }
    for(int i{0}; i < k; ++i){
        n -= mx / vec[i] + 1;
    }
    vp A;
    for(int i{0}; i < k; ++i){
        int a = (vec[i] - (mx % vec[i]));
        A.push_back({a, i + 1});
    }
    sort(A.begin(), A.end());
    cout << A[n - 1].second;
}
	

