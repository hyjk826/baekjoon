// 2022-11-14
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
#define MOD 1000000000
using namespace std;

int main() {
	fastio;
    int n;
    cin >> n;
    int a = abs(n);
    vi dp(a + 1);    
    dp[1] = 1;
    for(int i{2}; i <= a; ++i){
        dp[i] = dp[i - 1] + dp[i - 2];
        dp[i] %= MOD;
    }
    if(n == 0){
        cout << 0 << "\n" << 0;
    }
    else if(n < 0){
        if((-n) & 1){
            cout << 1 << "\n";
        }
        else{
            cout << -1 << "\n";
        }
        cout << dp[-n];
    }
    else{
        cout << 1 << "\n";
        cout << dp[n];
    }
}
	

