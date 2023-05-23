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
    int n;
    cin >> n;
    string str;
    cin >> str;
    int cnt{0};
    vi A;
    for(int i{0}; i <= n - 4; ++i){
        if(str.substr(i, 4) == "long"){
            cnt++;
            i += 3;
        }
        else{
            if(cnt) {
                A.push_back(cnt);
                cnt = 0;
            }
        }
    }
    if(cnt) A.push_back(cnt);
    vi dp(30);
    dp[0] = dp[1] = 1;
    for(int i{2}; i < 30; ++i){
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    ll ans{1};
    for(auto& i : A){
        ans *= dp[i];
    }
    cout << ans;
}
