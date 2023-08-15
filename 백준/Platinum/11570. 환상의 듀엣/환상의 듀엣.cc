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

void solve(){
	int n;
    cin >> n;
    vi vec(n + 1);
    for(int i{1}; i <= n; ++i) cin >> vec[i];
    vector<vi> dp(n + 1, vi(n + 1, -1));
    function<int(int,int)> f = [&](int a, int b){
        if(a == n || b == n) return 0;
        if(dp[a][b] != -1) return dp[a][b];
        int& ret = dp[a][b];
        int next = max(a, b) + 1;
        ret = MAX;
        if(a == 0){
            ret = min(ret, f(next, b));
        }
        else{
            ret = min(ret, abs(vec[a] - vec[next]) + f(next, b));
        }
        if(b == 0){
            ret = min(ret, f(a, next));
        }
        else{
            ret = min(ret, abs(vec[b] - vec[next]) + f(a, next));
        }
        return ret;
    };
    cout << f(0, 0);
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
