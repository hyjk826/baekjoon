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

int n;
string str;
int dp[5000][5000];

int f(int l, int r){
    if(dp[l][r] != -1) return dp[l][r];
    if(l == r) return dp[l][r] = 0;
    if(r == l + 1) {
        if(str[l] == str[r]) return dp[l][r] = 0;
        else return dp[l][r] = 1;
    }
    int mn{MAX};
    if(str[l] == str[r]) mn = min(mn, f(l + 1, r - 1));
    mn = min(mn, 1 + f(l, r - 1));
    mn = min(mn, 1 + f(l + 1, r));
    return dp[l][r] = mn;
}

int main(){
	fastio;
    cin >> n >> str;
    memset(dp, -1, sizeof(dp));
    cout << f(0, n - 1);
}
