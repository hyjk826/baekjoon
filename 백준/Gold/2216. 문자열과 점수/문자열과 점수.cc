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
#define MAX 2147000000
#define MOD 1000000007
typedef long long ll;
using namespace std;

void solve(){
    int x, y, z;
    cin >> x >> y >> z;
    int ans{-(int)1e9};
    string s, t;
    cin >> s >> t;
    int n = (int)s.size();
    int m = (int)t.size();
    vector<vi> dp(n + 1, vi(m + 1, -1));
    function<int(int,int)> f = [&](int a, int b){
        if(a == n && b == m) return 0;
        if(dp[a][b] != -1) return dp[a][b];
        if(a == n){
            return dp[a][b] = y + f(a, b + 1);
        }
        else if(b == m){
            return dp[a][b] = y + f(a + 1, b);
        }
        else{
            int& ret = dp[a][b];
            ret = -(int)1e9;
            if(s[a] != t[b]) ret = max(ret, f(a + 1, b + 1) + z);
            else ret = max(ret, f(a + 1, b + 1) + x);
            ret = max(ret, f(a + 1, b) + y);
            ret = max(ret, f(a, b + 1) + y);
            return ret;
        }
    };
    cout << f(0, 0) << "\n";
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
