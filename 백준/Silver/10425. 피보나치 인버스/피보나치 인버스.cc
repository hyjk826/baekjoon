// 2022-12-12
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


int main() {
	fastio;
    map<ll, int> mp;
    vl dp(100001);
    dp[0] = 0; dp[1] = 1;
    for(int i{2}; i <= 100000; ++i){
        dp[i] = dp[i - 1] + dp[i - 2];
        dp[i] %= (ll)1e18;
        mp[dp[i]] = i;
    }
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        if(str == "1") cout << 2 << "\n";
        else{
            if(str.size() > 18) str = str.substr((int)str.size() - 18);
            cout << mp[stoll(str)] << "\n";
        }
    }
}
	
