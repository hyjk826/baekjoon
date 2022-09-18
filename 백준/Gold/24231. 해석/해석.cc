// 2022-09-18
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

vector<vl> dp(300, vl(300, -1));
string str;

ll f(int l, int r){
    if(l > r) return 1;
    if(dp[l][r] != -1) return dp[l][r];
    if(r - l + 1 == 2){
        return dp[l][r] = (str[l] != str[r]);
    }
    dp[l][r] = 0;
    for(int i{l + 1}; i <= r; ++i){
        if(str[i] != str[l]){
            dp[l][r] += f(l + 1, i - 1) * f(i + 1, r);
            dp[l][r] %= MOD;
        }
    }
    return dp[l][r];
}


int main() {
	fastio;
    cin >> str;
    if(str.size() & 1){
        cout << 0;
        return 0;
    }
    cout << f(0, (int)str.size() - 1);
}
	

