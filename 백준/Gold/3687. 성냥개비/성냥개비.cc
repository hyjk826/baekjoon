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
	int arr[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    ll dp[101];
    for(int i{0}; i <= 100; ++i) dp[i] = (ll)1e17;
    dp[0] = 0;
    dp[1] = (ll)1e17;
    for(int i{2}; i <= 100; ++i){
        for(int j{0}; j <= 9; ++j){
            if(i < arr[j]) continue;
            ll k = dp[i - arr[j]] * 10 + j;
            if(k == 0) continue;
            dp[i] = min(dp[i], dp[i - arr[j]] * 10 + j);    
        }
    }
    int t;
    cin >> t;
    for(int i{0}; i < t; ++i){
        int n;
        cin >> n;
        cout << dp[n] << " ";
        if(n & 1) cout << 7 << string((n - 3) / 2, '1') << "\n";
        else cout << string(n / 2, '1') << "\n";
    }
}
