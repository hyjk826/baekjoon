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
#define MAX 1000000000
#define MOD 1000000007
using namespace std;

int main(){
	fastio;
    int n;
    cin >> n;
    string str;
    cin >> str;
    vi dp(n, MAX);
    dp[0] = 0;
    string s = "BOJ";
    for(int i{1}; i < n; ++i){
        int idx = s.find(str[i]);
        char c = s[(idx + 2) % 3];
        for(int j{0}; j < i; ++j){
            if(str[j] == c) dp[i] = min(dp[i], dp[j] + (i - j) * (i - j));
        }
    }
    if(dp[n - 1] == MAX) cout << -1;
    else cout << dp[n - 1];
}
