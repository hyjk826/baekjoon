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
	int t;
    t = 3;
    while(t--){
        int n;
        cin >> n;
        vp vec(n);
        int sum{0};
        for(int i{0}; i < n; ++i){
            cin >> vec[i].first >> vec[i].second;
            sum += vec[i].first * vec[i].second;
        }
        if(sum & 1) cout << 0 << "\n";
        else{
            sum /= 2;
            vi dp(sum + 1);
            dp[0] = 1;
            for(int i{0}; i < n; ++i){
                for(int j{sum - vec[i].first}; j >= 0; --j){
                    if(dp[j] == 0) continue;
                    for(int k{1}; k <= vec[i].second && j + k * vec[i].first <= sum; ++k){
                        dp[j + k * vec[i].first] = 1;
                    }
                }
            }
            if(dp[sum]) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
    }
}
