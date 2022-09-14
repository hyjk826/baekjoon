// 2022-09-14
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

string str;

bool f(int l, int r){
    if(l > r) return 1;
    if(str[l] == str[r]) return f(l + 1, r - 1);
    else return 0;
}

int main() {
	fastio;
    cin >> str;
    int n = (int)str.size();
    vi dp(n, MAX);
    for(int i{0}; i < n; ++i){
        for(int j{0}; j <= i; ++j){
            if(f(j, i)){
                if(j == 0) dp[i] = 1;
                else{
                    dp[i] = min(dp[i], dp[j - 1] + 1);
                }
            }
        }
    }
    cout << dp.back();
}
	

