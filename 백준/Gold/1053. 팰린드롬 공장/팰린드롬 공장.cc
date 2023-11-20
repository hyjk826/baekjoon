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

int dp[50][50];

void solve(){
	string str;
    cin >> str;
    int n = (int)str.size();
    int ans{MAX};
    for(int i{0}; i < n; ++i){
        for(int j{i}; j < n; ++j){
            swap(str[i], str[j]);                     
            memset(dp, -1, sizeof(dp));
            function<int(int,int)> f = [&](int a, int b){
                if(a > b || a == b) return 0;
                if(dp[a][b] != -1) return dp[a][b];
                int& ret = dp[a][b];
                ret = MAX;
                ret = min(ret, f(a + 1, b) + 1);
                ret = min(ret, f(a, b - 1) + 1);
                ret = min(ret, f(a + 1, b - 1) + 1);
                if(str[a] == str[b]) ret = min(ret, f(a + 1, b - 1));
                return ret;
            };
            if(i == j) ans = min(ans, f(0, n - 1));
            else ans = min(ans, f(0, n - 1) + 1);
            swap(str[i], str[j]);   
        }
    }
    cout << ans << "\n";
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
