// 2023-01-17
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
    string str;
    cin >> str;
    vs vec(2);
    for(int i{0}; i < 2; ++i){
        cin >> vec[i];
    }
    int n = (int)str.size();
    vector<vi> dp(n, vi(2));
    for(int i{0}; i < (int)vec[0].size(); ++i){
        for(int a{n - 1}; a >= 0; --a){
            for(int j{0}; j < 2; ++j){
                if(vec[j][i] == str[a]){
                    if(a == 0) dp[a][j]++;
                    else dp[a][j] += dp[a - 1][j ^ 1];
                }
            }
        }
    }
    cout << dp[n - 1][0] + dp[n - 1][1];
}
