// 2022-11-19
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
    int m, mod;
    cin >> m >> mod;
    vi A;
    for(int i{1}; i <= m; ++i){
        int sum{0};
        int c = i;
        while(c){
            sum += c % 10;
            c /= 10;
        }
        if(i % sum == 0) A.push_back(i);
    }   
    vi dp(m + 1);
    dp[0] = 1;
    for(auto& i : A){
        for(int j{0}; j + i <= m; ++j){
            dp[j + i] += dp[j];
            dp[j + i] %= mod;
        }
    }
    cout << dp[m];
}
	

