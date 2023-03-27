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
    int n, k, L;
    cin >> n >> k >> L;
    vi cnt(n);
    vi vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    for(int i{0}; i < k; ++i){
        int a;
        cin >> a;
        a--;
        cnt[a] += 1;
        if(a + L < n) cnt[a + L] -= 1;
    }
    for(int i{1}; i < n; ++i){
        cnt[i] += cnt[i - 1];
    }
    sort(cnt.begin(), cnt.end());
    sort(vec.begin(), vec.end());
    ll ans{0};
    for(int i{0}; i < n; ++i){
        if(cnt[i] > 31) continue;
        ans += vec[i] / (1LL << cnt[i]);
    }
    cout << ans;
}
