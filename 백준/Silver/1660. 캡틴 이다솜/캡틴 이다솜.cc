// 2022-09-05
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

int main() {
	fastio;
    int n;
    cin >> n;
    vi vec;
    int k{0};
    for(int i{0};;++i){
        k += i + 1;
        if(k > 300000) break;
        vec.push_back(k);
    }
    for(int i{1}; i < (int)vec.size(); ++i){
        vec[i] += vec[i - 1];
    }
    for(int i{0}; i < (int)vec.size(); ++i){
        if(vec[i] > 300000){
            vec.erase(vec.begin() + i, vec.end());
        }
    }
    vi dp(300001, MAX);
    dp[0] = 0;
    for(int i{1}; i <= 300000; ++i){
        for(auto& j : vec){
            if(j > i) break;
            dp[i] = min(dp[i], dp[i - j] + 1);
        }
    }
    cout << dp[n];
}
	

