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
    int n, k;
    cin >> n >> k;
    vl cnt(1000001);
    for(int i{0}; i < n; ++i){
        int a, b;
        cin >> b >> a;
        cnt[a] += b;
    }
    ll ans{0};
    for(int i{1}; i <= 1000000; ++i){
        cnt[i] += cnt[i - 1];
    }
    if(2 * k + 1 >= 1000000){
        cout << cnt.back(); return 0;
    }
    ans = cnt[2 * k];
    for(int i{2 * k + 1}; i <= 1000000; ++i){
        ans = max(ans, cnt[i] - cnt[i - 2 * k - 1]);
    }
    cout << ans;
}
