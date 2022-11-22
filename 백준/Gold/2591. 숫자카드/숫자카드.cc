// 2022-11-21
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
    string str;
    cin >> str;
    vl dp((int)str.size() + 1);
    dp[0] = 1;
    if(str[0] == '0'){
        cout << 0;
        return 0;
    }
    for(int i{1}; i <= (int)str.size(); ++i){
        if(str[i - 1] != '0'){
            dp[i] += dp[i - 1];
        }
        if(i >= 2){
            string t;
            t += str[i - 2];
            t += str[i - 1];
            if(stoi(t) <= 34 && stoi(t) >= 10){
                dp[i] += dp[i - 2];
            }
        }
    }
    cout << dp[(int)str.size()];
}
	

