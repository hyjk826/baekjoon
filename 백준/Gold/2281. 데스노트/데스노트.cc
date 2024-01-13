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
	int n, m;
    cin >> n >> m;
    vi vec(n);
    for(auto& i : vec) cin >> i;
    vector<vi> dp(n, vi(m, -1));
    function<int(int,int)> f = [&](int a, int b){
        if(dp[a][b] != -1) return dp[a][b];
        int& ret = dp[a][b];
        ret = MAX;
        if(b > 0){
            ret = (m - b + 1) * (m - b + 1) + f(a, 0);
        }
        if(b + vec[a] - 1 >= m){
            return ret = (m - b) * (m - b) + f(a, 0);
        }
        else{
            if(a == n - 1) return ret = 0;
            else{
                if(b + vec[a] + 1 + vec[a + 1] - 1 <= m - 1) ret = min(ret, f(a + 1, b + vec[a] + 1));
                else{
                    int k = m - (b + vec[a]);
                    ret = min(ret, k * k + f(a + 1, 0));
                }
            }
        }
        return ret;
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
