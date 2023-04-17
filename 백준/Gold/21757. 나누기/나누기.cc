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
    int n;
    cin >> n;
    vl vec(n + 1);
    for(int i{1}; i <= n; ++i){
        cin >> vec[i];
        vec[i] += vec[i - 1];
    }
    if(vec.back() % 4 == 0){
        ll k = vec.back() / 4;
        if(k == 0){
            int cnt{0};
            for(int i{1}; i < n; ++i){
                if(vec[i] == 0) cnt++;
            }
            cout << 1LL * cnt * (cnt - 1) * (cnt - 2) / 6; 
        }
        else{
            vl dp(4);
            dp[0] = 1;
            for(int i{1}; i < n; ++i){
                if(vec[i] % k == 0 && vec[i] / k <= 3 && vec[i] / k > 0){
                    ll a = vec[i] / k;
                    dp[a] += dp[a - 1];
                }
            }
            cout << dp.back();
        }
    }
    else cout << 0;
}
