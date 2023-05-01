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
    vp vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i].first >> vec[i].second;
    }
    sort(vec.begin(), vec.end(), [&](pi& x, pi& y){
        return x.second < y.second;
    });
    vl X(n), cnt(n);
    vl sumX(n);
    for(int i{0}; i < n; ++i){
        X[i] = vec[i].second;
        cnt[i] = vec[i].first;
        sumX[i] = X[i] * vec[i].first;
        if(i){
            cnt[i] += cnt[i - 1];
            sumX[i] += sumX[i - 1];
        }
    }
    while(q--){
        int x;
        cin >> x;
        int idx = lower_bound(X.begin(), X.end(), x) - X.begin();
        ll ans{0};
        if(idx - 1 >= 0) ans += (ll)cnt[idx - 1] * x - sumX[idx - 1];
        if(idx != n) {
            if(idx == 0) ans += sumX.back() - cnt.back() * x;
            else ans += (sumX.back() - sumX[idx - 1]) - (cnt.back() - cnt[idx - 1]) * x;
        }
        cout << ans << "\n";
    }

}
