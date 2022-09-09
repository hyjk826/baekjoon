// 2022-09-09
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

int main(){
    fastio;
    int n, k;
    cin >> n >> k;
    vi vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    ll l{1}, r{(ll)1e17};
    ll ans{0};
    while(l <= r){
        ll m{(l + r) / 2};
        ll sum{0};
        for(int i{0}; i < n; ++i){
            sum += vec[i] / m;
        }
        if(sum < k){
            r = m - 1;
        }
        else{
            l = m + 1;
            ans = max(ans, m);
        }
    }
    cout << ans;
}