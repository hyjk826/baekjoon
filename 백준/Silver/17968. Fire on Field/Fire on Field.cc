// 2022-11-13
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
    vi dp(n + 1, -1);
    dp[0] = dp[1] = 1;
    for(int i{2}; i <= n; ++i){
        set<int> st;
        for(int j{1}; i - 2 * j >= 0; ++j){
            int a = dp[i - 2 * j];
            int b = dp[i - j];
            st.insert(2 * b - a);
        }
        for(int j{1};;++j){
            if(!st.count(j)){
                dp[i] = j;
                break;
            }
        }
    }
    cout << dp[n];
}
	

