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
    int n, k;
    cin >> n >> k;
    vi vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    int l{0}, r{10000};
    int ans{MAX};
    while(l <= r){
        int m{(l + r) / 2};
        int cnt{1};
        int mn{MAX};
        int mx{0};
        for(int i{0}; i < n; ++i){
            if(max(mx, vec[i]) - min(mn, vec[i]) > m){
                cnt++;
                mn = vec[i];
                mx = vec[i];
            }
            else{
                mn = min(mn, vec[i]);
                mx = max(mx, vec[i]);
            }
        }
        if(cnt <= k){
            ans = min(ans, m);
            r = m - 1;
        }
        else l = m + 1;
    }
    cout << ans;
}
	

